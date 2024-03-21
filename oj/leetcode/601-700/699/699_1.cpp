#include <bits/stdc++.h>

using namespace std;

static constexpr int N = 2010;

auto get(vector<int>&xs, const int x) {
    return ranges::lower_bound(xs.begin(), xs.end(), x) - xs.begin();
}

struct Node {
    int l, r;
    int h;
    int lazy;
} tr[N << 2];

void build(int u, int l, int r) {
    tr[u] = {l, r};
    if (l != r) {
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    }
}

void push_up(int u) {
    tr[u].h = max(tr[u << 1].h, tr[u << 1 | 1].h);
}

void push_down(int u) {
    if (tr[u].lazy) {
        auto &l = tr[u << 1], &r = tr[u << 1 | 1];
        l.h = r.h = tr[u].lazy;
        l.lazy = r.lazy = tr[u].lazy;
        tr[u].lazy = 0;
    }
}

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].h;
    push_down(u);
    int mid = tr[u].l + tr[u].r >> 1;
    int res = 0;
    if (l <= mid) res = query(u << 1, l, r);
    if (r > mid) res = max(res, query(u << 1 | 1, l, r));
    push_up(u);
    return res;
}

void update(int u, int l, int r, int h) {
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].h = tr[u].lazy = h;
    } else {
        push_down(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) update(u << 1, l, r, h);
        if (r > mid) update(u << 1 | 1, l, r, h);
        push_up(u);
    }
}

class Solution {
public:
    static vector<int> fallingSquares(vector<vector<int>>&positions) {
        const size_t n = positions.size();
        vector<int> xs;
        xs.reserve(n << 1);
        for (auto&p: positions) {
            xs.emplace_back(p[0]);
            xs.emplace_back(p[0] + p[1] - 1);
        }
        ranges::sort(xs);
        xs.erase(ranges::unique(xs).begin(), xs.end());
        auto m = xs.size();
        build(1, 0, m - 1);
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int l = get(xs, positions[i][0]);
            int r = get(xs, positions[i][0] + positions[i][1] - 1);
            int h = query(1, l, r);
            update(1, l, r, h + positions[i][1]);
            res[i] = query(1, 0, m - 1);
        }
        return res;
    }
};
