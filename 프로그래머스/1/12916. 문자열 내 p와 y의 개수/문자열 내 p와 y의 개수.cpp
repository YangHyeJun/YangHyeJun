#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int p = 0;
    int y = 0;
    for (int i = 0; i < s.length(); i ++) {
        if ((char)tolower(s[i]) == 'p') {
            p ++;
        } else if ((char)tolower(s[i]) == 'y') {
            y ++;
        }
    }
    if (p == y) answer = true;
    else answer = false;
    return answer;
}