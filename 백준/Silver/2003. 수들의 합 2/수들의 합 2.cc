#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int left = 0;
    int right = 0;
    int sum = 0;
    int count = 0;

    while (true) {
        if (sum >= m) {
            if (sum == m) {
                count++;
            }
            sum -= a[left++];
        } else {
            if (right == n) {
                break;
            }
            sum += a[right++];
        }
    }

    cout << count << '\n';
    return 0;
}
