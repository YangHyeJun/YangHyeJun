#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    int l = 0;
    int r = n - 1;
    int answer = 0;
    sort(v.begin(), v.end());
    while(l < r) {
        int sum = v[l] + v[r];

        if (sum == m) {
            l ++;
            r --;
            answer ++;
        } else if (sum < m) {
            l ++;
        } else {
            r --;
        }
    }
    cout << answer << endl;
    return 0;
}