#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string t = "^#";
        for (char c: s) {
            t.push_back(c);
            t.push_back('#');
        }
        t.push_back('$');
        auto n = t.size();
        int d[n + 1];
        memset(d, 0, sizeof d);
        d[1] = 1;
        int mx = 0, idx = 0;
        for (int i = 2, l = 1, r = 1; i < n; i++) {
            if (i <= r) d[i] = min(d[l + r - i], r - i + 1);
            while (t[i - d[i]] == t[i + d[i]]) d[i]++;
            if (d[i] > r - i + 1) l = i - d[i] + 1, r = i + d[i] - 1;
            if (d[i] > mx) mx = d[i], idx = i;
        }
        string res;
        for (int i = idx - d[idx] + 1; i < idx + d[idx]; i++) {
            if (isalnum(t[i])) {
                res.push_back(t[i]);
            }
        }
        return res;
    }
};