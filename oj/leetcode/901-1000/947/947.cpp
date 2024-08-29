#include <bits/stdc++.h>

using namespace std;

const int N = 10010;

int p[N], sz[N];
int row[N], col[N];
bool vis[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

class Solution {
public:
    int removeStones(vector<vector<int>> &stones) {
        auto n = stones.size();
        iota(p, p + n, 0);
        fill(sz, sz + n, 1);
        memset(row, -1, sizeof row);
        memset(col, -1, sizeof col);
        memset(vis, 0, sizeof(bool) * n);
        int cnt = n;
        for (int i = 0; i < n; i++) {
            int x = stones[i][0], y = stones[i][1];
            if (~row[x]) {
                int pi = find(i), pr = find(row[x]);
                if (pi == pr) continue;
                if (sz[pi] > sz[pr]) swap(pi, pr);
                p[pi] = pr;
                sz[pr] += sz[pi];
                cnt--;
            }
            if (~col[y]) {
                int pi = find(i), pc = find(col[y]);
                if (pi == pc) continue;
                if (sz[pi] > sz[pc]) swap(pi, pc);
                p[pi] = pc;
                sz[pc] += sz[pi];
                cnt--;
            }
            row[x] = col[y] = i;
        }
        return n - cnt;
    }
};