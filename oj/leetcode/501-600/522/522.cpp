#include <bits/stdc++.h>

using namespace std;

bool is_subsequence(string &s, string &t) {
    if (s.size() > t.size()) return false;
    int n = s.size(), m = t.size(), i = 0, j = 0;
    while (i < n) {
        while (j < m && t[j] != s[i]) j++;
        if (j == m) break;
        i++, j++;
    }
    return i == n;
}

class Solution {
public:
    int findLUSlength(vector<string> &strs) {
        sort(strs.begin(), strs.end(), [](auto &a, auto &b) {
            return a.size() > b.size();
        });
        for (int i = 0; i < strs.size(); i++) {
            bool ok = true;
            for (int j = 0; j < strs.size(); j++) {
                if (j != i && is_subsequence(strs[i], strs[j])) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                return strs[i].size();
            }
        }
        return -1;
    }
};