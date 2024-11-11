#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int N = 100010;

struct Node {
    int l, r;
    bool lazy;
    int sum;
} tr[N << 2];

void push_up(int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void push_down(int u) {
    auto &l = tr[u << 1], &r = tr[u << 1 | 1];
    if (tr[u].lazy) {
        l.sum = l.r - l.l + 1 - l.sum, r.sum = r.r - r.l + 1 - r.sum;
        l.lazy = !l.lazy, r.lazy = !r.lazy;
        tr[u].lazy = false;
    }
}

void build(vector<int>&nums1, int u, int l, int r) {
    tr[u] = {l, r, false};
    if (l == r) {
        tr[u].sum = nums1[l];
    } else {
        const int mid = l + r >> 1;
        build(nums1, u << 1, l, mid);
        build(nums1, u << 1 | 1, mid + 1, r);
        push_up(u);
    }
}

void update(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].sum = tr[u].r - tr[u].l + 1 - tr[u].sum;
        tr[u].lazy = !tr[u].lazy;
    } else {
        push_down(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) update(u << 1, l, r);
        if (r > mid) update(u << 1 | 1, l, r);
        push_up(u);
    }
}

class Solution {
public:
    vector<long long> handleQuery(vector<int>&nums1, vector<int>&nums2, vector<vector<int>>&queries) {
        int n = nums1.size();
        build(nums1, 1, 0, n - 1);
        vector<LL> res;
        LL sum = accumulate(nums2.begin(), nums2.end(), 0LL);
        for (auto&q: queries) {
            int type = q[0];
            if (type == 1) {
                update(1, q[1], q[2]);
            } else if (type == 2) {
                sum += tr[1].sum * 1LL * q[1];
            } else {
                res.push_back(sum);
            }
        }
        return res;
    }
};
