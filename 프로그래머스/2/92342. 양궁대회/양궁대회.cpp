#include <string>
#include <vector>

using namespace std;


vector<int> lion;
vector<int> best, info2;

int bestDiff = 0;

int score(vector<int>& v) {
    int a = 0, r = 0;
    for (int i = 0; i < 11; i++) {
        int s = 10 - i;
        if (v[i] == 0 && info2[i] == 0) continue;
        if (v[i] > info2[i]) r += s;
        else a += s;
    }
    return r - a;
}

bool betterTie(vector<int>& cand, vector<int>& curBest) {
    for (int i = 10; i >= 0; i--) {
        if (cand[i] != curBest[i]) return cand[i] > curBest[i];
    }
    return false;
}

void dfs(int index, int n, vector<int>& v) {
    if (index == 11) {
        if (n != 0) return;
        int diff = score(v);
        if (diff > bestDiff || (diff == bestDiff && betterTie(v, best))) {
            bestDiff = diff;
            best = v;
        }
        return;
    }
    
    if (index == 10) {
        v[10] += n;
        dfs(11, 0, v);
        v[10] -= n;
        return;
    }
    
    dfs(index + 1, n, v);
    
    int req = info2[index] + 1;
    if (n >= req) {
        v[index] += req;
        dfs(index + 1, n - req, v);
        v[index] -= req;
    }
    
    
}

vector<int> solution(int n, vector<int> info) {
    info2 = info;
    bestDiff = -1;
    best.assign(11, 0);
    vector<int> lion(11, 0);

    dfs(0, n, lion);    

    if (bestDiff <= 0) return vector<int>{-1};
    return best;
}