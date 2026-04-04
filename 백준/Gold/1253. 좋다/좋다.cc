#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int answer = 0;

    for (int index = 0; index < n; index++) {
        int start = 0;
        int end = n - 1;
        int num = v[index];

        while (start < end) {
            if (start == index) {
                start++;
                continue;
            }
            if (end == index) {
                end--;
                continue;
            }

            int sum = v[start] + v[end];

            if (sum < num) {
                start++;
            } else if (sum > num) {
                end--;
            } else {
                answer++;
                break;
            }
        }
    }

    cout << answer;
    return 0;
}