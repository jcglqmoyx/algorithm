#include <bits/stdc++.h>

using namespace std;

vector<int> z_function(string &s, int m) {
    auto n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r && z[i - l] < r - i + 1) {
            z[i] = z[i - l];
        } else {
            z[i] = max(0, r - i + 1);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        }
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

class Solution {
public:
    int minStartingIndex(string s, string pattern) {
        auto n = s.size(), m = pattern.size();
        auto t = pattern + s;
        auto z1 = z_function(t, m);
        reverse(pattern.begin(), pattern.end());
        reverse(s.begin(), s.end());
        t = pattern + s;
        auto z2 = z_function(t, m);
        for (int i = m; i < n + 1; i++) {
            if (z1[i] + z2[m + n - i] + 1 >= m) {
                return i - m;
            }
        }
        return -1;
    }
};