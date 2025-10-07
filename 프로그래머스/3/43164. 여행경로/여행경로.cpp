#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(vector<vector<string>>& tickets, vector<string>& path, vector<bool>& visited, int count) {
    if (count == tickets.size()) return true;
    string cur = path.back();
    
    for (int i = 0; i < tickets.size(); i++) {
        if (!visited[i] && tickets[i][0] == cur) {
            path.push_back(tickets[i][1]);
            visited[i] = true;
            if(dfs(tickets, path, visited, count + 1)) return true;
            path.pop_back();
            visited[i] = false;
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(), tickets.end());
    vector<string> path;
    vector<bool> visited (tickets.size(), false);
    path.push_back("ICN");
    dfs(tickets, path, visited, 0);
    return path;
}