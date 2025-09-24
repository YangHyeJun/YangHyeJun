#include <string>
#include <vector>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int h = park.size();
    int w = park[0].size();
    
    vector<int> dp(w + 1, 0);
    int best = 0;
    
    for (int i = 1; i <= h; i++) {
        int prev_diag = 0; // 왼-위 대각선 값 (이전 행의 dp[j - 1])
        for (int j = 1; j <= w; j++) {
            int temp = dp[j];
            if (park[i - 1][j - 1] == "-1") {
                int left = dp[j - 1];
                int up = dp[j];
                int up_left = prev_diag;
                
                int val = left < up ? left : up;
                if (up_left < val) val = up_left;
                dp[j] = val + 1;
                if (dp[j] > best) best = dp[j];
            } else {
                dp[j] = 0;
            }
            prev_diag = temp;
        }    
    }
    int answer = -1;
    for (int m : mats) {
        if (m <= best && m > answer) answer = m;
    }
    return answer;
    return answer;
}