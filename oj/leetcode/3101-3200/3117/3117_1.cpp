#include <bits/stdc++.h>

using namespace std;

const int N = 10010, M = 14, INF = 0x3f3f3f3f;

int f[N], g[N];

struct Node {
    int l, r;
    int f;
} tr[N << 2];

void build(int u, int l, int r) {
    tr[u] = {l, r};
    if (l == r) tr[u].f = f[l];
    else {
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        tr[u].f = min(tr[u << 1].f, tr[u << 1 | 1].f);
    }
}

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].f;
    int mid = (tr[u].l + tr[u].r) >> 1;
    int res = INF;
    if (l <= mid) res = query(u << 1, l, r);
    if (r > mid) res = min(res, query(u << 1 | 1, l, r));
    return res;
}

int lg2[N];
int st[N][M];
int init = []() {
    lg2[1] = 0;
    for (int i = 2; i < N; i++) {
        lg2[i] = lg2[i >> 1] + 1;
    }
    return 0;
}();

int and_sum(int l, int r) {
    int len = r - l + 1;
    return st[l][lg2[len]] & st[r - (1 << lg2[len]) + 1][lg2[len]];
}

class Solution {
public:
    int minimumValueSum(vector<int> &nums, vector<int> &andValues) {
        auto n = nums.size(), m = andValues.size();

        for (int i = 0; i < n; i++) {
            st[i][0] = nums[i];
        }
        for (int j = 1; j <= lg2[n]; j++) {
            for (int i = 0; i < n; i++) {
                if (i + (1 << j) - 1 < n) {
                    st[i][j] = st[i][j - 1] & st[i + (1 << (j - 1))][j - 1];
                }
            }
        }

        memset(f, 0x3f, sizeof(int) * (n + 1));
        f[0] = 0;

        for (int i = 1; i <= m; i++) {
            build(1, 0, n);
            for (int j = i; j <= n; j++) {
                g[j] = INF;
                if (nums[j - 1] < andValues[i - 1]) continue;
                int l = i - 1, r = j - 1;
                while (l < r) {
                    int mid = (l + r + 1) >> 1;
                    if (and_sum(mid, j - 1) > andValues[i - 1]) r = mid - 1;
                    else l = mid;
                }
                if (and_sum(l, j - 1) != andValues[i - 1]) continue;
                int right = l;
                l = i - 1, r = j - 1;
                while (l < r) {
                    int mid = (l + r) >> 1;
                    if (and_sum(mid, j - 1) < andValues[i - 1]) l = mid + 1;
                    else r = mid;
                }
                int left = l;
                g[j] = query(1, left, right) + nums[j - 1];
            }
            memcpy(f, g, sizeof(int) * (n + 1));
        }
        return f[n] >= INF / 2 ? -1 : f[n];
    }
};