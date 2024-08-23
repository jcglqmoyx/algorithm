#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>> &rooms, vector<vector<int>> &queries) {
        auto n = rooms.size(), m = queries.size();
        int idx[m];
        iota(idx, idx + m, 0);
        sort(idx, idx + m, [&](int a, int b) {
            return queries[a][1] < queries[b][1];
        });
        set<pair<int, int>> id_size;
        for (auto &r: rooms) {
            id_size.emplace(r[0], r[1]);
        }
        sort(rooms.begin(), rooms.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        vector<int> res(m, -1);
        for (int u = 0, i = 0; u < rooms.size() && i < m; i++) {
            int id = idx[i];
            int preferred = queries[id][0], min_size = queries[id][1];
            while (u < n && rooms[u][1] < min_size) {
                id_size.erase({rooms[u][0], rooms[u][1]});
                u++;
            }
            if (u == n) break;
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