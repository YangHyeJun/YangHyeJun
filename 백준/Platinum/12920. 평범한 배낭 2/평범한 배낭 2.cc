#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> items;
    
    for (int i = 0; i < n; i++) {
        int v, c, k;
        cin >> v >> c >> k;
        
        int cnt = 1;
        while(k > 0) {
            int take = min(k, cnt);
            items.push_back({v * take, c * take});
            cnt *= 2;
            k -= take;
        }
    }
    
    
    // dp
    vector<int> dp(m + 1, 0);
    for (auto& item : items) {
        int weight = item.first;
        int value = item.second;
        for (int j = m; j >= weight; j--) {
            dp[j] = max(dp[j], dp[j - weight] + value);
        }
    }
    
    cout << dp[m];
    return 0;
}