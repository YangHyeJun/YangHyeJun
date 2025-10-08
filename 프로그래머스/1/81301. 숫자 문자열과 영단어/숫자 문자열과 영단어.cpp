#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    vector<string> numbers = {
        "zero", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine"
    };
    
    for (int i = 0; i < 10; i++) {
        int pos = 0;
        while ((pos = s.find(numbers[i], pos)) != string::npos) {
            s.replace(pos, numbers[i].length(), to_string(i));
        }
    }
    
    return stoi(s);
}