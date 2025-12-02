#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <functional>

using namespace std;

vector<pair<int, int>> node[5001];
int d[5001];

void dijkstra(int start) {
    const int INF = 1e9;

    for (int i = 0; i < 5001; i++) d[i] = INF;
    d[start] = 0;

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    pq.push({0, start});

    while(!pq.empty()) {
        int distance = pq.top().first;
        int current  = pq.top().second;
        pq.pop();

        if (d[current] < distance) continue;

        for (int i = 0; i < node[current].size(); i++) {
            int next = node[current][i].first;
            int weight = node[current][i].second;

            int nextDistance = distance + weight;

            if (nextDistance < d[next]) {
                d[next] = nextDistance;
                pq.push({nextDistance, next});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<tuple<int,int,int>> edges;
    edges.reserve(m);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.emplace_back(a, b, c);
    }

    int s, t;
    cin >> s >> t;

    for (auto &e : edges) {
        int a, b, c;
        tie(a, b, c) = e;
        node[a].push_back({b, c});
        node[b].push_back({a, c});
    }

    dijkstra(s);

    cout << d[t] << endl;

    return 0;
}
