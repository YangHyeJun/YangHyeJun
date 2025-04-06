#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int map[101][101];
bool visited[101][101];
int n, m;

void dfs(int x, int y) {
    visited[x][y] = true;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] && map[nx][ny] == 0) {
            dfs(nx, ny);
        }
    }
}

void input() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    return;
}

bool check() {
    vector<pair<int, int>> melt;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (map[i][j] == 1) {
                int contact = 0;
                for(int k = 0; k < 4; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if (map[x][y] == 0 && visited[x][y]) {
                        contact ++;
                    }
                }

                if (contact >= 2) {
                    melt.push_back({i, j});
                }
            }
        }
    }

    for(auto[x, y] : melt) {
        map[x][y] = 0;
    }

    return !melt.empty();
}
int main() {
    cin >> n >> m;
    int hours = 0;

    input();
    while(true) {
        memset(visited, false, sizeof(visited));
        dfs(0, 0);
        if (!check()) break;

        hours++;
    }

    cout << hours;

    return 0;
}