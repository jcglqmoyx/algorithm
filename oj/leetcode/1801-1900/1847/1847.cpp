#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>> &rooms, vector<vector<int>> &queries) {
        struct T {
            int preferred;
            int min_size;
            int idx;
        };
        auto m = queries.size();
        int idx[m];
        iota(idx, idx + m, 0);
        sort(idx, idx + m, [&](int a, int b) {
            return queries[a][1] < queries[b][1];
        });
        set<pair<int, int>> id_size, size_id;
        for (auto &r: rooms) {
            id_size.emplace(r[0], r[1]);
            size_id.emplace(r[1], r[0]);
        }
        vector<int> res(m, -1);
        for (int i = 0; i < m; i++) {
            int id = idx[i];
            int preferred = queries[id][0], min_size = queries[id][1];
            while (!size_id.empty() && size_id.begin()->first < min_size) {
                auto it = size_id.begin();
                id_size.erase(id_size.find({it->second, it->first}));
                size_id.erase(it);
            }
            if (!id_size.empty()) {
                auto it = id_size.lower_bound({preferred, 0});
                if (it != id_size.end()) {
                    res[id] = it->first;
                }
                if (it != id_size.begin()) {
                    --it;
                    if (res[id] == -1 || res[id] - preferred >= preferred - it->first) {
                        res[id] = it->first;
                    }
                }
            } else {
                res[id] = -1;
            }
        }
        return res;
    }
};