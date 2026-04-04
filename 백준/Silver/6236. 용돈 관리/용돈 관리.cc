#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int checkK(vector<int>& money, int mid) {
    int current = 0;
    int count = 0;

    for (int i = 0; i < money.size(); i++) {
        if (money[i] > current) {
            count++;
            current = mid;
        }
        current -= money[i];
    }
    return count;
}

int main() {
    int n, m, k;
    vector<int> money;
    
    // 입력
    cin >> n >> m;
    int max_cost = -1;
    int sum = 0;
    for (int i = 0; i < n; i ++) {
        int cost;
        cin >> cost;
        if (cost > max_cost) {
            max_cost = cost;
        }
        sum += cost;
        money.push_back(cost);
    }
    
    
    // Left = max(하루 최대 사용량) , Right = sum(총 사용량)
    // 이진탐색 진행
    int answer;
    int left = max_cost;    // 500
    int right = sum;        // 1901
    int mid = (left + right) / 2;
    
    int count = 0;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        int count = checkK(money, mid);

        if (count <= m) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << answer;
    return 0;
}