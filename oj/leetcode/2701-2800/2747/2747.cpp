#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>> &logs, int x, vector<int> &queries) {
        sort(logs.begin(), logs.end());
        auto m = queries.size();
        sort(logs.begin(), logs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        int idx[m];
        iota(idx, idx + m, 0);
        sort(idx, idx + m, [&](int a, int b) {
            return queries[a] < queries[b];
        });
        unordered_map<int, int> map;
        vector<int> res(m);
        for (int l = 0, r = 0, i = 0; i < m; i++) {
            int u = idx[i], q = queries[u];
            while (r < logs.size() && logs[r][1] <= q) {
                map[logs[r][0]]++;
                r++;
            }
            while (l < logs.size() && logs[l][1] < q - x) {
                map[logs[l][0]]--;
                if (map[logs[l][0]] == 0) {
                    map.erase(logs[l][0]);
                }
                l++;
            }
            res[u] = n - map.size();
        }
        return res;
    }
};