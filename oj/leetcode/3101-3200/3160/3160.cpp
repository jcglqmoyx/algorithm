#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries) {
        auto n = queries.size();
        unordered_map<int, int> color, cnt;
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int p = queries[i][0], c = queries[i][1];
            cnt[c]++;
            if (color.contains(p)) {
                cnt[color[p]]--;
                if (cnt[color[p]] == 0) {
                    cnt.erase(color[p]);
                }
            }
            color[p] = c;
            res[i] = (int) cnt.size();
        }
        return res;
    }
};