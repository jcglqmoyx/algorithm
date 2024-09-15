#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people) {
        unordered_map<string, int> map;
        auto n = req_skills.size(), m = people.size();
        for (int i = 0; i < n; i++) {
            map[req_skills[i]] = i;
        }
        vector<int> p(m);
        for (int i = 0; i < m; i++) {
            for (auto &s: people[i]) {
                p[i] |= 1 << map[s];
            }
        }
        int f[1 << n];
        memset(f, -1, sizeof f);
        f[0] = 0;
        auto dp = [&](auto &&dp, int mask) -> int {
            if (f[mask] != -1) return f[mask];
            f[mask] = 0x3f3f3f3f;
            for (int x: p) {
                if (mask & x) {
                    f[mask] = min(f[mask], dp(dp, mask ^ (mask & x)) + 1);
                }
            }
            return f[mask];
        };
        dp(dp, (1 << n) - 1);
        vector<int> res;
        for (int start = 0, mask = (1 << n) - 1; mask;) {
            for (int i = start; i < m; i++) {
                if ((mask & p[i]) && f[mask] == f[mask ^ (mask & p[i])] + 1) {
                    mask ^= mask & p[i];
                    res.emplace_back(i);
                    start = i + 1;
                    break;
                }
            }
        }
        return res;
    }
};