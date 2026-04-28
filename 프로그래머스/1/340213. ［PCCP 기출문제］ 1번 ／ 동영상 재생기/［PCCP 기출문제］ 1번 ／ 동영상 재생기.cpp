#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    string min = pos.substr(0,2);
    string sec = pos.substr(3,5);
    int m = stoi(min);
    int s = stoi(sec);
    int tot_sec = m * 60 + s;
    int oleft = stoi(op_start.substr(0,2)) * 60 + stoi(op_start.substr(3,5));
    int oright = stoi(op_end.substr(0,2)) * 60 + stoi(op_end.substr(3,5));
    int tot = stoi(video_len.substr(0,2)) * 60 + stoi(video_len.substr(3,5));
    for (int i = 0; i < commands.size(); i++) {
        if (tot_sec >= oleft && tot_sec <= oright) {
            tot_sec = oright;
        }
        if (commands[i] == "next") {
            tot_sec += 10;
            if (tot_sec >= tot) {
                tot_sec = tot;
            }
        } else if (commands[i] == "prev") {
            tot_sec -= 10;
            if (tot_sec <= 0) {
                tot_sec = 0;
            }
        }
    }
    if (tot_sec >= oleft && tot_sec <= oright) {
        tot_sec = oright;
    }
    if (tot_sec / 60 == 0) {
        answer += "00";
    } else if (tot_sec / 60 < 10) {
        answer += "0";
        answer += to_string(tot_sec / 60);
    } else {
        answer += to_string(tot_sec / 60);
    }
    answer += ":";
    if (tot_sec % 60 == 0) {
        answer += "00";
    } else if (tot_sec % 60 < 10) {
        answer += "0";
        answer += to_string(tot_sec % 60);
    } else {
        answer += to_string(tot_sec % 60);
    }
    return answer;
}