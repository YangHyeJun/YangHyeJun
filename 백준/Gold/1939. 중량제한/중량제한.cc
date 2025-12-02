#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dijkstra(int start, vector<pair<int, int>> v[], vector<int>& dist, int n) {
    priority_queue<pair<int,int>> pq; // 최대힙
    dist[start] = 1e9;                // 시작점은 무한대 중량 가능

    pq.push({dist[start], start});    // (중량 가능치, 노드)

    while (!pq.empty()) {
        int curWeight = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] > curWeight) continue;

        for (auto &nx : v[cur]) {
            int next = nx.first;
            int w = nx.second;

            int nextWeight = min(curWeight, w);

            if (nextWeight > dist[next]) {
                dist[next] = nextWeight;
                pq.push({nextWeight, next});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> dist(n + 1, 0);
    vector<pair<int,int>> v[n + 1];

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    int start, end;
    cin >> start >> end;

    dijkstra(start, v, dist, n);

    cout << dist[end] << endl;

    return 0;
}
