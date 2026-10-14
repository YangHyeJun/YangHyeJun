#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int n, m = 0;
    n = arr1.size();
    m = arr1[0].size();
    vector<vector<int>> answer(n, vector<int> (m, 0));
    for (int i = 0; i < arr1.size(); i++) {
        for (int j = 0; j < arr1[0].size(); j++) {
            answer[i][j] += arr1[i][j] + arr2[i][j];
        }
    }
    return answer;
}