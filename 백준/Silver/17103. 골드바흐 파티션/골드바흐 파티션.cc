#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;
bool prime[MAX + 1];

// 소수인가?
bool isDecimal(int n) {
    return prime[n];
}

// 골드바흐 파티션 계산
int partition(int number) {
    int half = number / 2;
    int cnt = 0;
    for (int i = 2; i <= half; i++) {
        if (isDecimal(i) && isDecimal(number - i)) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    for (int i = 2; i <= MAX; i++) prime[i] = true;
    for (int i = 2; i * i <= MAX; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                prime[j] = false;
            }
        }
    }

    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++) {
        cout << partition(v[i]) << "\n";
    }

    return 0;
}
