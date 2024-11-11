#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>> &intervals, vector<int> &queries) {
        struct T {
            int l, r;

            bool operator<(const T &t) const {
                return r - l > t.r - t.l;
            }
        };
        priority_queue<T> q;
        for (auto &interval: intervals) {
            q.emplace(interval[0], interval[1]);
        }
        auto m = queries.size();
        set<pair<int, int>> s = {{-1, 0}, {1e9, 0}};
        for (int i = 0; i < m; i++) {
            s.emplace(queries[i], i);
        }
        vector<int> res(m, -1);
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            auto it = s.upper_bound({t.r, 1e9});
            it--;
            while ((*it).first != -1) {
                auto pre = prev(it);
                if ((*it).first >= t.l) {
                    res[(*it).second] = t.r - t.l + 1;
                    s.erase(it);
                } else {
                    break;
                }
                it = pre;
            }
        }

        return res;
    }
};