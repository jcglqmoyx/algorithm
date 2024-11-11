#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

struct Node {
    int l, r;
    int cnt0;
    bool lazy;
} tr[N << 2];

void push_up(int u) {
    tr[u].cnt0 = tr[u << 1].cnt0 + tr[u << 1 | 1].cnt0;
}

void push_down(int u) {
    auto &l = tr[u << 1], &r = tr[u << 1 | 1];
    if (tr[u].lazy) {
        l.cnt0 = l.r - l.l + 1 - l.cnt0;
        r.cnt0 = r.r - r.l + 1 - r.cnt0;
        l.lazy = !l.lazy, r.lazy = !r.lazy;
        tr[u].lazy = false;
    }
}

void build(vector<int> &nums, int u, int l, int r) {
    tr[u] = {l, r};
    if (l == r) {
        tr[u].cnt0 = nums[l] == 0;
    } else {
        int mid = (l + r) >> 1;
        build(nums, u << 1, l, mid);
        build(nums, u << 1 | 1, mid + 1, r);
        push_up(u);
    }
}

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].cnt0;
    push_down(u);
    int mid = (tr[u].l + tr[u].r) >> 1;
    int res = 0;
    if (l <= mid) res = query(u << 1, l, r);
    if (r > mid) res = (res + query(u << 1 | 1, l, r));
    push_up(u);
    return res;
}

void modify(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].cnt0 = tr[u].r - tr[u].l + 1 - tr[u].cnt0;
        tr[u].lazy = !tr[u].lazy;
    } else {
        push_down(u);
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (l <= mid) modify(u << 1, l, r);
        if (r > mid) modify(u << 1 | 1, l, r);
        push_up(u);
    }
}

class Solution {
public:
    int minKBitFlips(vector<int> &nums, int k) {
        int n = nums.size(), res = 0;
        build(nums, 1, 0, n - 1);
        for (int i = 0; i + k - 1 < n; i++) {
            if (query(1, i, i)) {
                modify(1, i, i + k - 1);
                res++;
            }
        }
        return query(1, n - k, n - 1) == 0 ? res : -1;
    }
};