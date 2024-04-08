#include <bits/stdc++.h>

using namespace std;

const int N = 2e6;

int ls[N], rs[N], L[N], R[N], cnt[N], idx;
bool lazy[N];

void push_down(int u) {
    int mid = (L[u] + R[u]) >> 1;
    if (!ls[u]) ls[u] = idx++, L[ls[u]] = L[u], R[ls[u]] = mid;
    if (!rs[u]) rs[u] = idx++, L[rs[u]] = mid + 1, R[rs[u]] = R[u];
    if (lazy[u]) {
        cnt[ls[u]] = R[ls[u]] - L[ls[u]] + 1, cnt[rs[u]] = R[rs[u]] - L[rs[u]] + 1;
        lazy[ls[u]] = lazy[rs[u]] = true;
        lazy[u] = false;
    }
}

void update(int u, int l, int r) {
    if (L[u] >= l && R[u] <= r) {
        cnt[u] = R[u] - L[u] + 1;
        lazy[u] = true;
    } else {
        push_down(u);
        int mid = (L[u] + R[u]) >> 1;
        if (l <= mid) update(ls[u], l, r);
        if (r > mid) update(rs[u], l, r);
        cnt[u] = cnt[ls[u]] + cnt[rs[u]];
    }
}

class CountIntervals {
public:
    CountIntervals() {
        memset(ls, 0, sizeof ls);
        memset(rs, 0, sizeof rs);
        memset(L, 0, sizeof L);
        memset(R, 0, sizeof R);
        memset(cnt, 0, sizeof cnt);
        memset(lazy, false, sizeof lazy);
        idx = 0;
        L[idx] = 1, R[idx] = 1e9;
        idx++;
    }

    void add(int left, int right) {
        update(0, left, right);
    }

    int count() {
        return cnt[0];
    }
};