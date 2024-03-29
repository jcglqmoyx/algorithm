#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<string> &original, vector<string> &changed, vector<int> &cost) {
        using LL = long long;
        size_t n = 0;
        for (auto &s: original) n += s.size();

        int idx = 0, sid = 0;
        int son[n * 26][26], id[n * 26];
        memset(son, 0, sizeof son);
        memset(id, -1, sizeof id);

        auto insert = [&](string &s) {
            int p = 0;
            for (char c: s) {
                int u = c - 'a';
                if (!son[p][u]) son[p][u] = ++idx;
                p = son[p][u];
            }
            if (id[p] == -1) id[p] = sid++;
            return id[p];
        };
        auto m = cost.size() * 2;
        int h[m], w[m], e[m], ne[m], o = 0;
        memset(h, -1, sizeof h);
        auto add = [&](int a, int b, int c) {
            e[o] = b, w[o] = c, ne[o] = h[a], h[a] = o++;
        };
        for (auto i = 0; i < cost.size(); i++) {
            int a = insert(original[i]);
            int b = insert(changed[i]);
            add(a, b, cost[i]);
        }
        LL dist[m][m];
        memset(dist, 0x3f, sizeof dist);
        bool st[sid + 1];
        for (int start = 0; start < sid; start++) {
            memset(st, false, sizeof st);
            dist[start][start] = 0;
            priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<>> q;
            q.emplace(0, start);
            while (!q.empty()) {
                auto t = q.top();
                q.pop();
                if (st[t.second]) continue;
                st[t.second] = true;
                for (int i = h[t.second]; ~i; i = ne[i]) {
                    int j = e[i];
                    if (dist[start][j] > t.first + w[i]) {
                        dist[start][j] = t.first + w[i];
                        q.emplace(dist[start][j], j);
                    }
                }
            }
        }
        n = source.size();
        LL f[n + 1];
        memset(f, 0x3f, sizeof f);
        f[n] = 0;
        for (int l = n - 1; l >= 0; l--) {
            int ps = 0, pt = 0;
            if (source[l] == target[l]) f[l] = f[l + 1];
            for (int r = l; r < n; r++) {
                ps = son[ps][source[r] - 'a'];
                pt = son[pt][target[r] - 'a'];
                if (!ps || !pt) break;
                if (id[ps] == -1 || id[pt] == -1) continue;
                f[l] = min(f[l], f[r + 1] + dist[id[ps]][id[pt]]);
            }
        }
        return f[0] == 0x3f3f3f3f3f3f3f3f ? -1 : f[0];
    }
};