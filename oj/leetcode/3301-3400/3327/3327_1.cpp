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

        using LL = long long;
        LL p1[n + 1], p2[n + 1];
        LL h1[n + 1], h2[n + 1];
        LL BASE1 = 31, BASE2 = 37;
        LL MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
        p1[0] = p2[0] = 1;
        for (int i = 1; i <= n; i++) {
            p1[i] = p1[i - 1] * BASE1 % MOD1;
            p2[i] = p2[i - 1] * BASE2 % MOD2;
        }
        h1[0] = h2[0] = 0;
        for (int i = 1; i <= n; i++) {
            h1[i] = (h1[i - 1] * BASE1 + str[i - 1] - 'a') % MOD1;
            h2[i] = (h2[i - 1] * BASE2 + str[i - 1] - 'a') % MOD2;
        }

        reverse(str.begin(), str.end());
        LL hh1[n + 1], hh2[n + 1];
        hh1[0] = hh2[0] = 0;
        for (int i = 1; i <= n; i++) {
            hh1[i] = (hh1[i - 1] * BASE1 + str[i - 1] - 'a') % MOD1;
            hh2[i] = (hh2[i - 1] * BASE2 + str[i - 1] - 'a') % MOD2;
        }

        auto get = [&](const LL h1[n + 1], const LL h2[n + 1], int l, int r) -> pair<LL, LL> {
            return {
                    ((h1[r] - p1[r - l + 1] * h1[l - 1]) % MOD1 + MOD1) % MOD1,
                    ((h2[r] - p2[r - l + 1] * h2[l - 1]) % MOD2 + MOD2) % MOD2,
            };
        };
        auto check = [&](int l, int r) {
            l++, r++;
            return get(h1, h2, l, r) == get(hh1, hh2, n - r + 1, n - l + 1);
        };
        vector<bool> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = check(start[i], start[i] + end[i] - start[i]);
        }
        return res;
    }
};