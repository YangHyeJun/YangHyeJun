#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    for (int i = 0; i < schedules.size(); i++) {
        int hours = schedules[i] / 100;
        int minutes = schedules[i] % 100;
        if (minutes >= 50) {
            minutes = minutes + 10 - 60;
            hours += 1;
        } else {
            minutes += 10;
        }
        
        int limit = hours * 100 + minutes;
        
        bool isGood = true;
        for (int j = 0; j < timelogs[i].size(); j++) {
            int day = (startday + j) % 7;
            if (limit < timelogs[i][j] && day != 0 && day != 6) {
                isGood = false;
                break;
            }
        }
        if (isGood) answer ++;
    }
    return answer;
}