#include <bits/stdc++.h>

using namespace std;

const int N = 4e6;
const int INF = 0x3f3f3f3f;

int ls[N], rs[N], idx;
int L[N], R[N];
int mn[N];
bool lazy[N];

void extend(int u) {
    ls[u] = ++idx;
    rs[u] = ++idx;
    int mid = (L[u] + R[u]) >> 1;
    L[ls[u]] = L[u];
    R[ls[u]] = mid;
    L[rs[u]] = mid + 1;
    R[rs[u]] = R[u];
}

void push_down(int u) {
    if (lazy[u]) {
        lazy[ls[u]] = lazy[rs[u]] = true;
        mn[ls[u]] = min(mn[ls[u]], mn[u]);
        mn[rs[u]] = min(mn[rs[u]], mn[u]);
        lazy[u] = false;
    }
}

void update(int u, int l, int r) {
    if (!ls[u]) {
        extend(u);
    }
    if (L[u] >= l && R[u] <= r) {
        mn[u] = min(mn[u], r - l + 1);
        lazy[u] = true;
    } else {
        push_down(u);
        int mid = (L[u] + R[u]) >> 1;
        if (l <= mid) update(ls[u], l, r);
        if (r > mid) update(rs[u], l, r);
    }
}


int query(int u, int p) {
    if (!ls[u]) {
        extend(u);
    }
    if (L[u] == R[u]) return mn[u];
    push_down(u);
    int mid = (L[u] + R[u]) >> 1;
    if (p <= mid) return query(ls[u], p);
    return query(rs[u], p);
}

class Solution {
public:
    vector<int> minInterval(vector<vector<int>> &intervals, vector<int> &queries) {
        int mx = 0;
        memset(ls, 0, sizeof ls);
        memset(rs, 0, sizeof rs);
        memset(mn, 0x3f, sizeof mn);
        memset(lazy, 0, sizeof lazy);
        L[0] = 1, R[0] = 1e7, idx = 0;

        for (auto &v: intervals) {
            update(0, v[0], v[1]);
        }
        auto m = queries.size();
        vector<int> res(m, -1);
        for (int i = 0; i < m; i++) {
            int t = query(0, queries[i]);
            if (t != INF) res[i] = t;
        }
        return res;
    }
};