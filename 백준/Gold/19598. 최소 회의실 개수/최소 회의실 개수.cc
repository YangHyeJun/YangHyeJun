#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct meeting {
    int start;
    int end;
};

bool comp(const meeting &m1, const meeting &m2) {
    if (m1.start == m2.start) return m1.end < m2.end;
    return m1.start < m2.start;
}

int main() {
    int n;
    cin >> n;
    vector<meeting> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].start >> v[i].end;
    }

    sort(v.begin(), v.end(), comp);

    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(v[0].end);

    for (int i = 1; i < n; i++) {
        if (pq.top() <= v[i].start) {
            pq.pop();
        }

        pq.push(v[i].end);
    }

    cout << pq.size() << endl;
    
    return 0;
}
