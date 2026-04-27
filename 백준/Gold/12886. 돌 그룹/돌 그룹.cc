#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Info {
    int a, b, c;
};

bool visited[1501][1501];

int bfs(Info stone) {
    int sum = stone.a + stone.b + stone.c;

    if (sum % 3 != 0) return 0;

    queue<Info> q;

    int arr[3] = {stone.a, stone.b, stone.c};
    sort(arr, arr + 3);

    q.push({arr[0], arr[1], arr[2]});
    visited[arr[0]][arr[1]] = true;

    while (!q.empty()) {
        Info cur = q.front();
        q.pop();

        if (cur.a == cur.b && cur.b == cur.c) {
            return 1;
        }

        int stones[3] = {cur.a, cur.b, cur.c};

        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 3; j++) {
                if (stones[i] == stones[j]) continue;

                int next[3] = {cur.a, cur.b, cur.c};

                int x = stones[i];
                int y = stones[j];

                if (x > y) swap(x, y);

                // 작은 쪽 x는 2배, 큰 쪽 y는 x만큼 감소
                next[i] = x + x;
                next[j] = y - x;

                sort(next, next + 3);

                if (!visited[next[0]][next[1]]) {
                    visited[next[0]][next[1]] = true;
                    q.push({next[0], next[1], next[2]});
                }
            }
        }
    }

    return 0;
}

int main() {
    Info stone;
    cin >> stone.a >> stone.b >> stone.c;

    cout << bfs(stone);

    return 0;
}