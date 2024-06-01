#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        vector<vector<int>> g(26);
        int res = -1;
        for (int i = 0; i < s.size(); i++) {
            int j = i + 1;
            while (j < s.size() && s[j] == s[i]) j++;
            int u = s[i] - 'a';
            g[u].emplace_back(j - i);
            i = j - 1;
        }
        for (auto &v: g) {
            if (v.empty()) continue;
            while (v.size() < 3) { v.emplace_back(-1); }
            sort(v.begin(), v.end(), greater<>());
            res = max({res, v[0] - 2, min(v[0] - 1, v[1]), v[2]});
        }
        return res ? res : -1;
    }
};