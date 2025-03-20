#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct info {
    int deadline;
    int ramyun;
};

bool comp(const info &i1, const info &i2) {
    if(i1.deadline == i2.deadline) {
        return i1.ramyun > i2.ramyun;
    }

    return i1.deadline < i2.deadline;
}

int main() {
    int n;
    cin >> n;

    vector<info> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].deadline >> v[i].ramyun;
    }

    sort(v.begin(), v.end(), comp);

    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 0;

    for(int i = 0; i < v.size(); i++) {
        pq.push(v[i].ramyun);
        ans += v[i].ramyun;

        if (pq.size() > v[i].deadline) {
            ans -= pq.top();
            pq.pop();
        }
    }

    cout << ans;

    return 0;
}