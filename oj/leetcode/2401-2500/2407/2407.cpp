#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

struct Node {
    int l, r;
    int f;
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
    tr[u].f = max(tr[u << 1].f, tr[u << 1 | 1].f);
}

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].f;
    int mid = tr[u].l + tr[u].r >> 1;
    int res = 0;
    if (l <= mid) res = query(u << 1, l, r);
    if (r > mid) res = max(res, query(u << 1 | 1, l, r));
    return res;
}

void update(int u, int p, int val) {
    if (tr[u].l == tr[u].r) {
        tr[u].f = val;
    } else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (p <= mid) update(u << 1, p, val);
        else update(u << 1 | 1, p, val);
        push_up(u);
    }
}

class Solution {
public:
    static int lengthOfLIS(vector<int>&nums, int k) {
        const int mx = *ranges::max_element(nums.begin(), nums.end());
        build(1, 1, mx);
        int res = 0;
        for (const auto x: nums) {
            const int f = query(1, max(1, x - k), x - 1);
            update(1, x, f + 1);
            res = max(res, f + 1);
        }
        return res;
    }
};
