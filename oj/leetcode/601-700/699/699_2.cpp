#include <bits/stdc++.h>

using namespace std;

class Solution {
    static constexpr int N = 80010;
    int idx{};
    int L[N]{}, R[N]{};
    int ls[N]{}, rs[N]{};
    int H[N]{}, lazy[N]{};

    void push_up(int u) {
        H[u] = max(H[ls[u]], H[rs[u]]);
    }

    void push_down(int u) {
        int mid = L[u] + R[u] >> 1;
        if (ls[u] == 0) ls[u] = idx++, L[ls[u]] = L[u], R[ls[u]] = mid, H[ls[u]] = H[u];
        if (rs[u] == 0) rs[u] = idx++, L[rs[u]] = mid + 1, R[rs[u]] = R[u], H[rs[u]] = H[u];
        if (lazy[u]) {
            lazy[ls[u]] = lazy[rs[u]] = H[ls[u]] = H[rs[u]] = lazy[u];
            lazy[u] = 0;
        }
    }

    int query(int u, int l, int r) {
        if (L[u] >= l && R[u] <= r) return H[u];
        int mid = L[u] + R[u] >> 1;
        push_down(u);
        int res = 0;
        if (l <= mid) res = query(ls[u], l, r);
        if (r > mid) res = max(res, query(rs[u], l, r));
        push_up(u);
        return res;
    }

    void update(int u, int l, int r, int v) {
        if (L[u] >= l && R[u] <= r) {
            H[u] = lazy[u] = v;
        } else {
            push_down(u);
            int mid = L[u] + R[u] >> 1;
            if (l <= mid) update(ls[u], l, r, v);
            if (r > mid) update(rs[u], l, r, v);
            push_up(u);
        }
    }

public:
    vector<int> fallingSquares(vector<vector<int>>&positions) {
        int n = positions.size();
        L[0] = 1, R[0] = 1e8, idx++;
        vector<int> res(n);
        int max_r = 0;
        for (int i = 0; i < n; i++) {
            int l = positions[i][0], h = positions[i][1], r = l + h - 1;
            max_r = max(max_r, r);
            int mx = query(0, l, r);
            update(0, l, r, mx + h);
            res[i] = query(0, 1, max_r);
        }
        return res;
    }
};
