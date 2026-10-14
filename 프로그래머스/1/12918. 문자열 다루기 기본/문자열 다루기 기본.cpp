#include <string>
#include <cctype> // isdigit 함수를 사용하기 위함

using namespace std;

bool solution(string s) {
    // 1. 문자열의 길이가 4 혹은 6이 아니면 false 반환
    if (s.length() != 4 && s.length() != 6) {
        return false;
    }
    
    // 2. 각 문자가 숫자로만 구성되어 있는지 확인
    for (char c : s) {
        if (!isdigit(c)) {
            return false;
        }
    }
    
    return true;
}