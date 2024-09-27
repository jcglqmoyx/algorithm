#include <bits/stdc++.h>

using namespace std;

const int N = 60010;

int ls[N], rs[N], idx;
int L[N], R[N];
int mx[N];
int lazy[N];

void push_down(int root) {
    if (!ls[root]) {
        ls[root] = ++idx, rs[root] = ++idx;
        int mid = (L[root] + R[root]) >> 1;
        L[ls[root]] = L[root], R[ls[root]] = mid;
        L[rs[root]] = mid + 1, R[rs[root]] = R[root];
    }
    if (lazy[root]) {
        lazy[ls[root]] += lazy[root], lazy[rs[root]] += lazy[root];
        mx[ls[root]] += lazy[ls[root]], mx[rs[root]] += lazy[rs[root]];
        lazy[root] = 0;
    }
}

void push_up(int root) {
    mx[root] = max({mx[root], mx[ls[root]], mx[rs[root]]});
}

int query(int root, int l, int r) {
    if (L[root] >= l && R[root] <= r) {
        return mx[root];
    }
    push_down(root);
    int res = 0;
    int mid = (L[root] + R[root]) >> 1;
    if (l <= mid) res = query(ls[root], l, r);
    if (r > mid) res = max(res, query(rs[root], l, r));
    push_up(root);
    return res;
}

void update(int root, int l, int r) {
    if (L[root] >= l && R[root] <= r) {
        mx[root]++;
        lazy[root]++;
    } else {
        push_down(root);
        int mid = (L[root] + R[root]) >> 1;
        if (l <= mid) update(ls[root], l, r);
        if (r > mid) update(rs[root], l, r);
        push_up(root);
    }
}

class MyCalendarTwo {
public:
    MyCalendarTwo() {
        memset(ls, 0, sizeof ls);
        memset(rs, 0, sizeof rs);
        memset(L, 0, sizeof L);
        memset(R, 0, sizeof R);
        memset(mx, 0, sizeof mx);
        memset(lazy, 0, sizeof lazy);
        idx = 0;
        L[0] = 0, R[0] = 1e9;
    }

    bool book(int start, int end) {
        if (query(0, start, end - 1) >= 2) {
            return false;
        }
        update(0, start, end - 1);
        return true;
    }
};