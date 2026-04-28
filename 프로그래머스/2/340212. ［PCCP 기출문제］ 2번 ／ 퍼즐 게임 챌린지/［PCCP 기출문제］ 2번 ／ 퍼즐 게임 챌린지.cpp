#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long calculateCost(const vector<int>& diffs, const vector<int>& times, int level) {
    long long cost = 0;

    for (int i = 0; i < diffs.size(); i++) {
        if (diffs[i] <= level) {
            cost += times[i];
        } else {
            cost += 1LL * (times[i - 1] + times[i]) * (diffs[i] - level) + times[i];
        }
    }

    return cost;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int left = 1;
    int right = *max_element(diffs.begin(), diffs.end());
    int answer = right;

    while (left <= right) {
        int mid = (left + right) / 2;

        long long cost = calculateCost(diffs, times, mid);

        if (cost <= limit) {
            answer = mid;
            right = mid - 1; // 더 낮은 level 가능한지 확인
        } else {
            left = mid + 1; // level을 올려야 함
        }
    }

    return answer;
}