#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

struct Node {
    int l, r;
    int mx;
} tr[N << 2];

void build(vector<int> &v, int u, int l, int r) {
    tr[u] = {l, r};
    if (l != r) {
        int mid = (l + r) >> 1;
        build(v, u << 1, l, mid);
        build(v, u << 1 | 1, mid + 1, r);
        tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
    } else {
        tr[u].mx = v[l];
    }
}

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].mx;
    int mid = (tr[u].l + tr[u].r) >> 1;
    int res = 0;
    if (l <= mid) res = query(u << 1, l, r);
    if (r > mid) res = max(res, query(u << 1 | 1, l, r));
    return res;
}

class Solution {
public:
    long long numberOfSubarrays(vector<int> &v) {
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < v.size(); i++) {
            map[v[i]].push_back(i);
        }

        auto helper = [&](int low, int high, int x) {
            auto &v = map[x];
            int l = 0, r = v.size() - 1;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (v[mid] >= low) r = mid;
                else l = mid + 1;
            }
            int left = l;
            l = left, r = v.size() - 1;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (v[mid] >= high) r = mid;
                else l = mid + 1;
            }
            int right = l;
            return right - left + 1;
        };

        int n = v.size();
        build(v, 1, 0, n - 1);
        long long res = 0;
        for (int i = 0; i < n; i++) {
            int l = 0, r = i;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (query(1, mid, i) <= v[i]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            res += helper(l, i, v[i]);
        }
        return res;
    }
};
