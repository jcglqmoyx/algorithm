#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n = static_cast<int>(s.size()), len = n / k;
        unordered_map<string, int> cnt;
        for (int i = 0; i < n; i += len) {
            cnt[s.substr(i, len)]++;
        }
        for (int i = 0; i < n; i += len) {
            auto sub = t.substr(i, len);
            if (cnt[sub]) {
                cnt[sub]--;
            } else {
                return false;
            }
        }
        return true;
    }
};