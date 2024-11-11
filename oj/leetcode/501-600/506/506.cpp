#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int> &score) {
        auto n = score.size();
        auto v = score;
        sort(v.begin(), v.end());
        unordered_map<int, int> mp;
        for (auto i = n; i > 0; i--) {
            mp[v[i - 1]] = n - i + 1;
        }
        vector<string> res(n);
        for (int i = 0; i < n; i++) {
            if (mp[score[i]] == 1) res[i] = "Gold Medal";
            else if (mp[score[i]] == 2) res[i] = "Silver Medal";
            else if (mp[score[i]] == 3) res[i] = "Bronze Medal";
            else res[i] = to_string(mp[score[i]]);
        }
        return res;
    }
};