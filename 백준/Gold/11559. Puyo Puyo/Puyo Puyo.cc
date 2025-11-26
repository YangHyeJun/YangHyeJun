#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<char>> field(12, vector<char>(6));
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool bfs(int x, int y, vector<vector<bool>>& visited, vector<pair<int,int>>& removeList) {
    char color = field[x][y];
    queue<pair<int,int>> q;
    vector<pair<int,int>> tmp;

    visited[x][y] = true;
    q.push({x,y});
    tmp.push_back({x,y});

    while(!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
            if(visited[nx][ny]) continue;
            if(field[nx][ny] != color) continue;

            visited[nx][ny] = true;
            q.push({nx,ny});
            tmp.push_back({nx,ny});
        }
    }

    if(tmp.size() >= 4){
        for(auto &p: tmp) removeList.push_back(p);
        return true;
    }
    return false;
}

void applyGravity() {
    for(int col = 0; col < 6; col++){
        int emptyRow = 11;
        for(int row = 11; row >= 0; row--){
            if(field[row][col] != '.'){
                char temp = field[row][col];
                field[row][col] = '.';
                field[emptyRow][col] = temp;
                emptyRow--;
            }
        }
    }
}

int main(){
    for(int i=0;i<12;i++){
        for(int j=0;j<6;j++){
            cin >> field[i][j];
        }
    }

    int chain = 0;

    while(true){
        vector<vector<bool>> visited(12, vector<bool>(6,false));
        vector<pair<int,int>> removeList;
        bool exploded = false;

        for(int i=0;i<12;i++){
            for(int j=0;j<6;j++){
                if(field[i][j] != '.' && !visited[i][j]) {
                    if(bfs(i, j, visited, removeList)) {
                        exploded = true;
                    }
                }
            }
        }

        if(!exploded) break;

        for(auto &p: removeList){
            field[p.first][p.second] = '.';
        }

        applyGravity();
        
        chain++;
    }

    cout << chain << endl;
    return 0;
}
