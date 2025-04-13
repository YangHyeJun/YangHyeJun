#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    unordered_map<char, int> freq;
    int left = 0;
    int maxLen = 0;

    for (int right = 0; right < s.size(); ++right) {
        freq[s[right]]++;
        while (freq.size() > n) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) {
                freq.erase(s[left]);
            }
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    cout << maxLen << endl;
    return 0;
}
