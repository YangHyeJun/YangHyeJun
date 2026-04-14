#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> ps(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        ps[i] = ps[i - 1] + v[i - 1];
    }

    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        cout << ps[e] - ps[s - 1] << '\n';
    }
}
