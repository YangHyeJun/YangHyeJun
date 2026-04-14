#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> lesson(N);
    int left = 0;
    int right = 0;

    for (int i = 0; i < N; i++) {
        cin >> lesson[i];
        left = max(left, lesson[i]);
        right += lesson[i];
    }

    int answer = right;

    while (left <= right) {
        int mid = (left + right) / 2;

        int count = 1;
        int sum = 0;

        for (int i = 0; i < N; i++) {
            if (sum + lesson[i] > mid) {
                count++;
                sum = lesson[i];
            } else {
                sum += lesson[i];
            }
        }

        if (count <= M) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << '\n';
    return 0;
}