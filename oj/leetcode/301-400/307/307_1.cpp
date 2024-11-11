#include <bits/stdc++.h>

using namespace std;

const int N = 30010;

struct Node {
    int l, r;
    int s;
} tr[N << 2];

void push_up(int u) {
    tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
}

void build(vector<int> &nums, int u, int l, int r) {
    tr[u] = {l, r};
    if (l == r) {
        tr[u].s = nums[l];
    } else {
        int mid = (l + r) >> 1;
        build(nums, u << 1, l, mid);
        build(nums, u << 1 | 1, mid + 1, r);
        push_up(u);
    }
}

void modify(int u, int p, int v) {
    if (tr[u].l == tr[u].r) {
        tr[u].s = v;
    } else {
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (p <= mid) modify(u << 1, p, v);
        else modify(u << 1 | 1, p, v);
        push_up(u);
    }
}

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) {
        return tr[u].s;
    }
    int mid = (tr[u].l + tr[u].r) >> 1;
    int res = 0;
    if (l <= mid) res = query(u << 1, l, r);
    if (r > mid) res += query(u << 1 | 1, l, r);
    return res;
}

class NumArray {
public:
    NumArray(vector<int> &nums) {
        build(nums, 1, 0, (int) nums.size() - 1);
    }

    void update(int index, int val) {
        modify(1, index, val);
    }

    int sumRange(int left, int right) {
        return query(1, left, right);
    }
};