#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] == 0 || visited[i][j]) continue;

            number_of_area++;
            int color = picture[i][j];
            int area_size = 0;

            queue<pair<int,int>> q;
            q.push({i, j});
            visited[i][j] = true;
            
            while(!q.empty()) {
                auto [cx, cy] = q.front(); q.pop();
                area_size ++;
                
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cx + dx[dir];
                    int ny = cy + dy[dir];
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                    if (visited[nx][ny]) continue;
                    if (picture[nx][ny] != color) continue;

                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
            max_size_of_one_area = max(max_size_of_one_area, area_size);

        }
    }
    return {number_of_area, max_size_of_one_area};
}
/*
    1110
    1220
    1001
    0001
    0003
    0003
    */