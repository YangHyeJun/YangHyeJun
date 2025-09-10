#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    queue<int> q;
    for (int i = 0; i < players.size(); i++) {
        while (true) {
            int discountHour = q.front();
            if (i >= discountHour && q.size() > 0) q.pop();
            else break;
        }
        
        
        int playerCount = players[i];
        if ((q.size() + 1) * m <= playerCount) {
            int n = playerCount - q.size() * m; // 13 - 1 * 3 = 10
            int c = n / m;
            for (int j = 0; j < c; j++) {
                q.push(i + k);
                answer ++;
            }
        }
        cout << "hours : " << i << "," << q.size() << endl;

    }
    return answer;
}