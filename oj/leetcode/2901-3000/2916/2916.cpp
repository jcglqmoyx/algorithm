#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumCounts(vector<int>&nums) {
        int n = nums.size(), mod = 1e9 + 7;

        struct Node {
            int l, r;
            int val;
            int sum;
            int lazy;
        } tr[n << 2];

        function<void(int, int, int)> build = [&](int u, int l, int r) {
            tr[u] = {l, r};
            if (l != r) {
                const int mid = l + r >> 1;
                build(u << 1, l, mid);
                build(u << 1 | 1, mid + 1, r);
            }
        };

        auto push_up = [&](int u) {
            tr[u].val = (tr[u << 1].val + tr[u << 1 | 1].val) % mod;
            tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % mod;
        };

        auto change = [&](int u, int dt) {
            const int len = tr[u].r - tr[u].l + 1;
            tr[u].sum = (tr[u].sum + tr[u].val * 2LL * dt + dt * 1LL * dt * len) % mod;
            tr[u].val = (tr[u].val + len * 1LL * dt) % mod;
        };

        auto push_down = [&](int u) {
            auto &l = tr[u << 1], &r = tr[u << 1 | 1];
            if (tr[u].lazy) {
                change(u << 1, tr[u].lazy);
                change(u << 1 | 1, tr[u].lazy);
                l.lazy += tr[u].lazy;
                r.lazy += tr[u].lazy;
                tr[u].lazy = 0;
            }
        };

        function<void(int, int, int)> update = [&](int u, int l, int r) {
            if (tr[u].l >= l && tr[u].r <= r) {
                const int len = tr[u].r - tr[u].l + 1;
                tr[u].sum = (tr[u].sum + tr[u].val * 2 % mod + len) % mod;
                tr[u].val = (tr[u].val + len) % mod;
                tr[u].lazy++;
            } else {
                push_down(u);
                int mid = tr[u].l + tr[u].r >> 1;
                if (l <= mid) update(u << 1, l, r);
                if (r > mid) update(u << 1 | 1, l, r);
                push_up(u);
            }
        };

        build(1, 1, n);
        unordered_map<int, int> pos;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int&p = pos[nums[i - 1]];
            update(1, p + 1, i);
            p = i;
            res = (res + tr[1].sum) % mod;
        }
        return res;
    }
};