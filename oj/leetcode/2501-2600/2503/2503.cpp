#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries) {
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        int n = grid.size(), m = grid[0].size();
        bool st[n][m];
        memset(st, 0, sizeof st);
        struct T {
            int v;
            int x, y;

            bool operator<(const T &t) const {
                return v > t.v;
            }
        };
        priority_queue<T> q;
        q.emplace(grid[0][0], 0, 0);
        vector<int> v;
        v.reserve(n * m);
        st[0][0] = true;
        while (!q.empty()) {
            for (auto it = q.size(); it; it--) {
                auto t = q.top();
                q.pop();
                v.emplace_back(t.v);
                for (int i = 0; i < 4; i++) {
                    int a = t.x + dx[i], b = t.y + dy[i];
                    if (a < 0 || a == n || b < 0 || b == m || st[a][b]) continue;
                    q.emplace(grid[a][b], a, b);
                    st[a][b] = true;
                }
            }
        }
        vector<int> res(queries.size());
        map<int, vector<int>> mp;
        for (int i = 0; i < queries.size(); i++) {
            mp[queries[i]].emplace_back(i);
        }
        int i = 0;
        for (auto &[k, p]: mp) {
            while (i < v.size() && v[i] < k) i++;
            for (int idx: p) {
                res[idx] = i;
            }
        }
        return res;
    }
};