#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set < string > set;
        int res = 0;
        auto dfs = [&](auto &&dfs, int u) -> void {
            if (u == s.size()) {
                res = max(res, static_cast<int>(set.size()));
            } else {
                for (int end = u; end < s.size(); end++) {
                    auto sub = s.substr(u, end - u + 1);
                    if (!set.contains(sub)) {
                        set.emplace(sub);
                        dfs(dfs, end + 1);
                        set.erase(sub);
                    }
                }
            }
        };
        dfs(dfs, 0);
        return res;
    }
};