#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> findAnswer(vector<int> &parent, string s) {
        int n = static_cast<int>(parent.size());
        int h[n], e[n], ne[n], idx = 0;
        memset(h, -1, sizeof h);
        for (int i = n - 1; i; i--) {
            // 因为链式前向星是头插法，所以这里先枚举一个node的序号较大的子节点
            e[idx] = i, ne[idx] = h[parent[i]], h[parent[i]] = idx++;
        }
        string str;
        int start[n], end[n], time = 0;
        auto dfs = [&](auto &&dfs, int u) -> void {
            start[u] = time;
            for (int i = h[u]; ~i; i = ne[i]) {
                dfs(dfs, e[i]);
            }
            str.push_back(s[u]);
            end[u] = time++;
        };

        dfs(dfs, 0);

        s = "^#";
        for (char c: str) {
            s.push_back(c);
            s.push_back('#');
        }
        s.push_back('$');
        int m = static_cast<int>(s.size());
        int d[m + 1];
        memset(d, 0, sizeof d);
        d[1] = 1;
        for (int i = 2, l = 1, r = 1; i < m; i++) {
            if (i <= r) d[i] = min(d[l + r - i], r - i + 1);
            while (s[i - d[i]] == s[i + d[i]]) d[i]++;
            if (i + d[i] - 1 > r) l = i - d[i] + 1, r = i + d[i] - 1;
        }

        vector<bool> res(n);
        for (int i = 0; i < n; i++) {
            int l = (start[i] + 1) * 2;
            int r = (end[i] + 1) * 2;
            res[i] = d[(l + r) >> 1] >= (r - l) / 2 + 1;
        }
        return res;
    }
};