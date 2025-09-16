#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer;
    const char digits[3] = {'1', '2', '4'};
    
    while (n > 0) {
        n--;                     
        answer += digits[n % 3];  
        n /= 3;
    }
    reverse(answer.begin(), answer.end());
    return answer;
}