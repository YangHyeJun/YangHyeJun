#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool visited[201][201];
bool result[201];
int cup[3];

void bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    while(!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        int c = cup[2] - a - b;

        if (a == 0) {
            result[c] = true;
        }

        int water[3] = {a, b, c};

        for(int i = 0; i < 3; i ++) {
            for(int j = 0; j < 3; j++) {
                if (i == j) continue;
                int next[3] =  {water[0], water[1], water[2]};

                int move = min(water[i], cup[j] - water[j]);
                next[i] -= move;
                next[j] += move;

                if (!visited[next[0]][next[1]]) {
                    visited[next[0]][next[1]] = true;
                    q.push({next[0], next[1]});
                }
            }
        }
    }
}

int main() {
    cin >> cup[0] >> cup[1] >> cup[2];

    bfs();

    for(int i = 0; i <= 200; i++) {
        if (result[i]) cout << i << " ";
    }

    return 0;
}