#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Node {
    int x, y, dist;
};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool check(vector<string>& place) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (place[i][j] == 'P') {
                queue<Node> q;
                vector<vector<bool>> visited(5, vector<bool>(5, false));
                q.push({i, j, 0});
                visited[i][j] = true;

                while (!q.empty()) {
                    auto [x, y, dist] = q.front();
                    q.pop();

                    if (dist >= 1 && dist <= 2 && place[x][y] == 'P') {
                        // 맨해튼 거리 2 이내에서 다른 P를 발견함 → 거리두기 위반
                        return false;
                    }

                    if (dist >= 2) continue; // 더 이상 탐색할 필요 없음

                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
                        if (visited[nx][ny]) continue;
                        if (place[nx][ny] == 'X') continue; // 파티션이면 통과 X

                        visited[nx][ny] = true;
                        q.push({nx, ny, dist + 1});
                    }
                }
            }
        }
    }
    return true; // 위반 없음
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (auto& place : places) {
        if (check(place)) answer.push_back(1);
        else answer.push_back(0);
    }
    return answer;
}
