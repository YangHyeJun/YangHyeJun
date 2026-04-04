#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<int> inDegree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        inDegree[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;

    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            pq.push(i);
        }
    }

    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();

        ans.push_back(cur);

        for (int next : graph[cur]) {
            inDegree[next]--;
            if (inDegree[next] == 0) {
                pq.push(next);
            }
        }
    }

    for (int x : ans) {
        cout << x << ' ';
    }

    return 0;
}