#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    int last = -1;
    for (int i = 0; i < arr.size(); i++) {
        if (i == 0) {
            last = arr[i];
            answer.push_back(arr[i]);
        }
        else {
            if (last != arr[i]) {
                answer.push_back(arr[i]);
                last = arr[i];
            }
        }
    }
    return answer;
}