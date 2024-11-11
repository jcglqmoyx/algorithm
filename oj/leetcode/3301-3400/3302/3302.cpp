#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> validSequence(string s, string pattern) {
        int n = s.size(), m = pattern.size();
        int suf[n + 1];
        memset(suf, 0, sizeof suf);
        for (int i = n - 1, j = m - 1; i >= 0; i--) {
            suf[i] = suf[i + 1];
            if (j >= 0 && s[i] == pattern[j]) {
                suf[i]++;
                j--;
            }
        }
        vector<int> res(m);
        bool changed = false;
        for (int i = 0, j = 0; i < n; i++) {
            if (s[i] == pattern[j] || !changed && j + 1 + suf[i + 1] >= m) {
                res[j] = i;
                if (s[i] != pattern[j]) changed = true;
                if (++j == m) return res;
            }
        }
        return {};
    }
};