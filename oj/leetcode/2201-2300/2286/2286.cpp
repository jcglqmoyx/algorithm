#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int N = 50010;

int m;
int cnt[N];

struct Node {
    int l, r;
    int mn;
    LL sum;
    bool lazy;
} tr[N << 2];

void build(int u, int l, int r) {
    tr[u] = {l, r};
    if (l != r) {
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }
}

void push_up(int u) {
    auto &l = tr[u << 1], &r = tr[u << 1 | 1];
    tr[u].mn = min(l.mn, r.mn);
    tr[u].sum = l.sum + r.sum;
}

void push_down(int u) {
    auto &l = tr[u << 1], &r = tr[u << 1 | 1];
    if (tr[u].lazy) {
        l.sum = (l.r - l.l + 1LL) * tr[u].mn, l.mn = tr[u].mn, l.lazy = true;
        r.sum = (r.r - r.l + 1LL) * tr[u].mn, r.mn = tr[u].mn, r.lazy = true;
        tr[u].lazy = false;
    }
}

int query_min(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].mn;
    push_down(u);
    int mid = tr[u].l + tr[u].r >> 1;
    int res = 1e9;
    if (l <= mid) res = query_min(u << 1, l, r);
    if (r > mid) res = min(res, query_min(u << 1 | 1, l, r));
    push_up(u);
    return res;
}

LL query_sum(int u, int l, int r) {
    if (l > r) return 0;
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    push_down(u);
    int mid = tr[u].l + tr[u].r >> 1;
    LL res = 0;
    if (l <= mid) res = query_sum(u << 1, l, r);
    if (r > mid) res += query_sum(u << 1 | 1, l, r);
    push_up(u);
    return res;
}

void update(int u, int l, int r, int val) {
    if (l > r) return;
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].sum = (tr[u].r - tr[u].l + 1LL) * val;
        tr[u].mn = val;
        tr[u].lazy = true;
    } else {
        push_down(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) update(u << 1, l, r, val);
        if (r > mid) update(u << 1 | 1, l, r, val);
        push_up(u);
    }
}

class BookMyShow {
    int n, last;

public:
    BookMyShow(int n, int _m) {
        memset(cnt, 0, sizeof(int) * n);
        this->n = n, m = _m, this->last = 0;
        build(1, 0, n - 1);
    }

    vector<int> gather(int k, int maxRow) const {
        if (last > maxRow || k > m) return {};
        int l = last, r = maxRow + 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (m - query_min(1, last, mid) >= k) r = mid;
            else l = mid + 1;
        }
        if (l > maxRow) return {};
        int idx = query_min(1, l, l);
        update(1, l, l, idx + k);
        return {l, idx};
    }

    bool scatter(int k, int maxRow) {
        if (last > maxRow) return false;
        int l = last, r = maxRow + 1;
        while (l < r) {
            int mid = l + r >> 1;
            if ((mid - last + 1LL) * m - query_sum(1, last, mid) >= k) r = mid;
            else l = mid + 1;
        }
        if (l > maxRow) return false;

        update(1, l, l, query_min(1, l, l) + k - ((l - last) * 1LL * m - query_sum(1, last, l - 1)));
        update(1, last, l - 1, m);

        last = l;
        return true;
    }
};