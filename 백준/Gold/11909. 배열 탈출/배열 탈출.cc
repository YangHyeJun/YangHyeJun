#include <iostream>
using namespace std;

static long long dp[2223][2223];
static int A[2223][2223];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
        }
    }

    const long long INF = 9e18;

    // DP 배열 초기화
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = INF;
        }
    }

    dp[1][1] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

            if (i == 1 && j == 1) continue;

            long long best = INF;

            // 위에서 내려오기
            if (i > 1) {
                long long need = 0;
                if (A[i - 1][j] <= A[i][j])
                    need = (long long)A[i][j] - A[i - 1][j] + 1;
                best = dp[i - 1][j] + need;
            }

            // 왼쪽에서 오기
            if (j > 1) {
                long long need = 0;
                if (A[i][j - 1] <= A[i][j])
                    need = (long long)A[i][j] - A[i][j - 1] + 1;
                long long fromLeft = dp[i][j - 1] + need;

                if (fromLeft < best)
                    best = fromLeft;
            }

            dp[i][j] = best;
        }
    }

    cout << dp[n][n];
    return 0;
}
