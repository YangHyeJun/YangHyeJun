#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

bool bfs(vector<Point>& locations) {
    int n = locations.size();
    vector<bool> visited(n, false);
    queue<int> q;
    
    q.push(0);
    visited[0] = true;
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        if (abs(locations[curr].x - locations[n - 1].x) + abs(locations[curr].y - locations[n - 1].y) <= 1000) {
            return true;
        }
        
        for (int i = 1; i < n; i++) {
            if (!visited[i] && abs(locations[curr].x - locations[i].x) + abs(locations[curr].y - locations[i].y) <= 1000) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    
    return false;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<Point> locations(n + 2);
        
        for (int i = 0; i < n + 2; i++) {
            cin >> locations[i].x >> locations[i].y;
        }
        
        if (bfs(locations)) {
            cout << "happy" << endl;
        } else {
            cout << "sad" << endl;
        }
    }
    
    return 0;
}
