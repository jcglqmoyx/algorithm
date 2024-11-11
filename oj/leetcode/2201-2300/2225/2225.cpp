#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches) {
        int lose[100001]{};
        bool st[100001]{};
        int mx = 0;
        for (auto &m: matches) {
            st[m[0]] = st[m[1]] = true;
            lose[m[1]]++;
            mx = max(mx, max(m[0], m[1]));
        }
        vector<vector<int>> res = {{},
                                   {}};
        for (int i = 1; i <= mx; i++) {
            if (st[i]) {
                if (!lose[i]) res[0].emplace_back(i);
                else if (lose[i] == 1) res[1].emplace_back(i);
            }
        }
        return res;
    }
};