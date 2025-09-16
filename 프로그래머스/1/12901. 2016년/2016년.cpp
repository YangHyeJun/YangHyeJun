#include <string>
#include <vector>
using namespace std;

string solution(int a, int b) {
    int day[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string date[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

    int sum = 0;
    for (int i = 0; i < a - 1; i++) {
        sum += day[i];
    }
    sum += (b - 1);

    int idx = (5 + sum) % 7;

    return date[idx];
}
