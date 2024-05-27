#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

const int N = 50010;

struct Node {
    int l, r;
    unsigned int f00, f01, f10, f11;
} tr[N << 2];

void push_up(int u) {
    auto &root = tr[u], &l = tr[u << 1], &r = tr[u << 1 | 1];
    root.f00 = max(l.f00 + r.f10, l.f01 + r.f00);
    root.f01 = max(l.f00 + r.f11, l.f01 + r.f01);
    root.f10 = max(l.f10 + r.f10, l.f11 + r.f00);
    root.f11 = max(l.f11 + r.f01, l.f10 + r.f11);
}

void build(vector<int> &nums, int u, int l, int r) {
    tr[u] = {l, r};
    if (l == r) {
        tr[u].f11 = max(nums[l], 0);
    } else {
        int mid = (l + r) >> 1;
        build(nums, u << 1, l, mid);
        build(nums, u << 1 | 1, mid + 1, r);
        push_up(u);
    }
}

void update(int u, int p, int v) {
    if (tr[u].l == tr[u].r) tr[u].f11 = max(v, 0);
    else {
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (p <= mid) update(u << 1, p, v);
        else update(u << 1 | 1, p, v);
        push_up(u);
    }
}

class Solution {
public:
    int maximumSumSubsequence(vector<int> &nums, vector<vector<int>> &queries) {
        int n = nums.size();
        build(nums, 1, 0, n - 1);
        unsigned int res = 0;
        for (auto &q: queries) {
            update(1, q[0], q[1]);
            res = (res + tr[1].f11) % MOD;
        }
        return res;
    }
};