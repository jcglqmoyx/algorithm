#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int possibleStringCount(string word, int k) {
        int MOD = 1e9 + 7;
        int n = static_cast<int>(word.size());
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            while (j < n && word[j] == word[i]) j++;
            v.emplace_back(j - i);
            i = j - 1;
        }
        n = static_cast<int>(v.size());
        long long res = 1;
        for (int i = 0; i < n; i++) {
            if (v[i] > 1) res = res * (v[i]) % MOD;
        }
        if (k <= n) return res;
        else k -= n;

        int f[k], s[k];
        fill(s, s + k, 1);
        for (int cnt: v) {
            for (int i = 0; i < k; i++) {
                int limit = min(cnt - 1, i);
                f[i] = s[i];
                if (i - limit - 1 >= 0) {
                    f[i] = (f[i] - s[i - limit - 1] + MOD) % MOD;
                }
            }
            for (int i = 1; i < k; i++) {
                s[i] = (s[i - 1] + f[i]) % MOD;
            }
        }
        for (int i = 0; i < k; i++) {
            res = (res - f[i] + MOD) % MOD;
        }
        return res;
    }
};