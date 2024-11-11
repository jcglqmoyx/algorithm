#include <bits/stdc++.h>

using namespace std;

const int N = 50010, M = N << 2;

int d[N];
bool st[N];
int h[N], e[M], ne[M], idx;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

class Solution {
public:
    vector<vector<int>> constructGridLayout(int n, vector<vector<int>> &edges) {
        memset(d, 0, sizeof(int) * n);
        memset(st, 0, sizeof(bool) * n);
        memset(h, -1, sizeof(int) * n);
        idx = 0;
        for (auto &edge: edges) {
            int x = edge[0], y = edge[1];
            d[x]++, d[y]++;
            add(x, y), add(y, x);
        }
        int min_degree = 4, max_degree = 1, top_left = 0;
        for (int i = 0; i < n; i++) {
            if (d[i] < min_degree) {
                min_degree = d[i];
                top_left = i;
            }
            max_degree = max(max_degree, d[i]);
        }
        vector<vector<int>> res;
        vector<int> row;
        row.emplace_back(top_left);
        st[top_left] = true;
        int prev = top_left;
        if (min_degree == 1) {
            do {
                for (int i = h[prev]; ~i; i = ne[i]) {
                    int j = e[i];
                    if (st[j]) continue;
                    row.emplace_back(j);
                    st[j] = true;
                    prev = j;
                }
            } while (d[prev] != 1);
            res.emplace_back(row);
        } else {
            do {
                for (int i = h[prev]; ~i; i = ne[i]) {
                    int j = e[i];
                    if (st[j] || (d[j] > max_degree - 1 && n != 4)) continue;
                    row.emplace_back(j);
                    prev = j;
                    st[j] = true;
                    break;
                }
            } while (d[prev] != 2);
            res.emplace_back(row);
            auto c = row.size(), r = n / c;
            for (int i = 1; i < r; i++) {
                for (int u = h[res.back()[0]]; ~u; u = ne[u]) {
                    int x = e[u];
                    if (st[x]) continue;
                    row[0] = x;
                    st[x] = true;
                    break;
                }
                for (int j = 1; j < c; j++) {
                    for (int u = h[row[j - 1]]; ~u; u = ne[u]) {
                        int x = e[u];
                        if (st[x]) continue;
                        bool ok = false;
                        for (int v = h[res.back()[j]]; ~v; v = ne[v]) {
                            int y = e[v];
                            if (y == x) {
                                ok = true;
                                break;
                            }
                        }
                        if (ok) {
                            row[j] = x;
                            st[x] = true;
                            break;
                        }
                    }
                }
                res.emplace_back(row);
            }
        }
        return res;
    }
};