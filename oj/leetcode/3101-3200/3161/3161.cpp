#include <bits/stdc++.h>

using namespace std;

const int N = 50010;

struct Node {
    int l, r;
    int mx;
} tr[N << 2];

void build(int u, int l, int r) {
    tr[u] = {l, r, 0};
    if (l != r) {
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }
}

void update(int u, int p, int v) {
    if (tr[u].l == tr[u].r) tr[u].mx = v;
    else {
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (p <= mid) update(u << 1, p, v);
        else update(u << 1 | 1, p, v);
        tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
    }
}

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].mx;
    int mid = (tr[u].l + tr[u].r) >> 1;
    int res = 0;
    if (l <= mid) res = query(u << 1, l, r);
    if (r > mid) res = max(res, query(u << 1 | 1, l, r));
    return res;
}

class Solution {
public:
    vector<bool> getResults(vector<vector<int>> &queries) {
        int mx = 0;
        for (auto &q: queries) mx = max(mx, q[1]);
        mx++;
        build(1, 0, mx);
        set<int> s{0, mx};
        vector<bool> res;
        for (auto &q: queries) {
            int type = q[0], x = q[1];
            auto it = s.lower_bound(x);
            int l = *prev(it), r = *it;
            if (type == 1) {
                s.emplace(x);
                update(1, x, x - l), update(1, r, r - x);
            } else if (type == 2) {
                int sz = q[2];
                res.emplace_back(max(query(1, 1, l), x - l) >= sz);
            }
        }
        return res;
    }
};