#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int g;
    cin >> g;

    int think = 1;
    int current = 1;

    vector<int> ans;

    while(current <= g) {
        int c = current * current;
        int t = think * think;
        if (c - t < g) {
            current += 1;
        } else if (c - t > g) {
            think += 1;
        } else {
            ans.push_back(current);
            think += 1;
        }
    }

    sort(ans.begin(), ans.end());

    if (ans.empty()) {
        cout << -1;
    } else {
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i] << endl;
        }
    }

    return 0;
}