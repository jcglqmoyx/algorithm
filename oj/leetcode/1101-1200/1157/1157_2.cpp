#include <bits/stdc++.h>

using namespace std;

static constexpr int N = 2e4 + 5;

struct Node {
    int l, r;
    int val, cnt;

    Node operator+(const Node&node) const {
        Node t{min(l, node.l), max(r, node.r)};
        if (val == node.val) {
            t.val = val;
            t.cnt = cnt + node.cnt;
        } else if (cnt > node.cnt) {
            t.val = val;
            t.cnt = cnt - node.cnt;
        } else {
            t.val = node.val;
            t.cnt = node.cnt - cnt;
        }
        return t;
    }
} tr[N << 2];

void build(vector<int>&arr, int u, int l, int r) {
    tr[u] = {l, r};
    if (l == r) {
        tr[u].val = arr[l];
        tr[u].cnt = 1;
    } else {
        const int mid = (l + r) >> 1;
        build(arr, u << 1, l, mid), build(arr, u << 1 | 1, mid + 1, r);
        tr[u] = tr[u << 1] + tr[u << 1 | 1];
    }
}

Node ask(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u];
    int mid = tr[u].l + tr[u].r >> 1;
    if (l > mid) return ask(u << 1 | 1, l, r);
    if (r <= mid) return ask(u << 1, l, r);
    return ask(u << 1, l, r) + ask(u << 1 | 1, l, r);
}

class MajorityChecker {
    unordered_map<int, vector<int>> map;

public:
    explicit MajorityChecker(vector<int>&arr) {
        for (int i = 0; i < arr.size(); i++) {
            map[arr[i]].push_back(i);
        }
        build(arr, 1, 0, arr.size() - 1);
    }

    int query(int left, int right, int threshold) {
        auto t = ask(1, left, right);
        auto&v = map[t.val];
        auto cnt = ranges::upper_bound(v.begin(), v.end(), right) - ranges::lower_bound(v.begin(), v.end(), left);
        if (cnt >= threshold) return t.val;
        return -1;
    }
};
