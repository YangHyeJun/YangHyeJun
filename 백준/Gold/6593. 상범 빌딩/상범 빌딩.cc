#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <tuple>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int L, R, C;
        if (!(cin >> L >> R >> C)) return 0;
        if (L == 0 && R == 0 && C == 0) break;

        vector<vector<string>> grid(L, vector<string>(R));
        int sz = -1, sx = -1, sy = -1;
        int ez = -1, ex = -1, ey = -1;

        for (int l = 0; l < L; ++l) {
            for (int r = 0; r < R; ++r) {
                string row;
                cin >> row;
                grid[l][r] = row;
                for (int c = 0; c < C; ++c) {
                    if (row[c] == 'S') { sz = l; sx = r; sy = c; }
                    else if (row[c] == 'E') { ez = l; ex = r; ey = c; }
                }
            }
        }

        vector<vector<vector<int>>> dist(L, vector<vector<int>>(R, vector<int>(C, -1)));
        queue<tuple<int,int,int>> q;
        dist[sz][sx][sy] = 0;
        q.emplace(sz, sx, sy);

        int dz[6] = { 1, -1, 0, 0, 0, 0 };
        int dx[6] = { 0, 0, 1, -1, 0, 0 };
        int dy[6] = { 0, 0, 0, 0, 1, -1 };

        int answer = -1;

        while (!q.empty()) {
            auto [z, x, y] = q.front(); q.pop();
            if (z == ez && x == ex && y == ey) {
                answer = dist[z][x][y];
                break;
            }
            for (int dir = 0; dir < 6; ++dir) {
                int nz = z + dz[dir];
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nz < 0 || nz >= L || nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if (grid[nz][nx][ny] == '#') continue;
                if (dist[nz][nx][ny] != -1) continue;
                dist[nz][nx][ny] = dist[z][x][y] + 1;
                q.emplace(nz, nx, ny);
            }
        }

        if (answer == -1) cout << "Trapped!\n";
        else cout << "Escaped in " << answer << " minute(s)." << '\n';
    }
    return 0;
}
