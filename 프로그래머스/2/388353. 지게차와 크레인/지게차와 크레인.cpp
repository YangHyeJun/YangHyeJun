#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    
    int n = storage.size();
    int m = storage[0].size();
    
    vector<vector<char>> v(n, vector<char> (m));
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j++) {
            v[i][j] = storage[i][j];
        }
    }
    
    queue<pair<int,int>> waste; // 외부 공기 BFS 용도(이 이름 그대로 사용)
    
    for (int i = 0; i < (int)requests.size(); i++) {
        char target = requests[i][0];
        
        // use == true 이면 크레인(문자 길이 2), false면 지게차(문자 길이 1)
        bool use = (requests[i].size() > 1);
        
        if (use) {
            // 크레인: target 전부 제거
            for (int y = 0; y < n; ++y) {
                for (int x = 0; x < m; ++x) {
                    if (v[y][x] == target) v[y][x] = '.';
                }
            }
        } else {
            // 지게차: 현재 시점 외부 공기에 접한 target만 제거
            // 1) 외부 공기 표시 ('.' 중에서 바깥과 연결된 칸들)
            vector<vector<bool>> air(n, vector<bool>(m, false));
            // waste 큐 재초기화
            waste = queue<pair<int,int>>();
            
            auto try_push = [&](int y, int x) {
                if (y < 0 || y >= n || x < 0 || x >= m) return;
                if (v[y][x] != '.') return;   // 빈칸만 공기 확장
                if (air[y][x]) return;
                air[y][x] = true;
                waste.push({y, x});
            };
            
            // 테두리에서 시작
            for (int x = 0; x < m; ++x) {
                try_push(0, x);
                try_push(n - 1, x);
            }
            for (int y = 0; y < n; ++y) {
                try_push(y, 0);
                try_push(y, m - 1);
            }
            
            // BFS로 외부 공기 확장
            while (!waste.empty()) {
                auto [cy, cx] = waste.front(); waste.pop();
                for (int d = 0; d < 4; ++d) {
                    int ny = cy + dy[d], nx = cx + dx[d];
                    if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                    if (v[ny][nx] != '.') continue;
                    if (air[ny][nx]) continue;
                    air[ny][nx] = true;
                    waste.push({ny, nx});
                }
            }
            
            // 2) 접근 가능한 target 수집 (동시 제거 위해 목록화)
            vector<pair<int,int>> toRemove;
            auto isEdge = [&](int y, int x) {
                return (y == 0 || y == n - 1 || x == 0 || x == m - 1);
            };
            
            for (int y = 0; y < n; ++y) {
                for (int x = 0; x < m; ++x) {
                    if (v[y][x] != target) continue;
                    
                    bool accessible = false;
                    if (isEdge(y, x)) {
                        // 테두리에 붙은 컨테이너는 바로 외부와 접함
                        accessible = true;
                    } else {
                        // 외부 공기(air=true)인 빈칸과 인접하면 접근 가능
                        for (int d = 0; d < 4; ++d) {
                            int ny = y + dy[d], nx = x + dx[d];
                            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                            if (v[ny][nx] == '.' && air[ny][nx]) {
                                accessible = true;
                                break;
                            }
                        }
                    }
                    if (accessible) toRemove.push_back({y, x});
                }
            }
            
            // 3) 동시 제거
            for (auto &p : toRemove) {
                v[p.first][p.second] = '.';
            }
        }
    }
    
    // 남은 컨테이너 수 계산
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < m; ++x) {
            if (v[y][x] != '.') ++answer;
        }
    }
    return answer;
}
