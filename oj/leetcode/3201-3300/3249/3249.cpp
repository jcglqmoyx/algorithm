#include <bits/stdc++.h>

using namespace std;

const int N = 100010, M = N << 1;

int h[N], e[M], ne[M], idx;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u, int p, int &res) {
    int child = -1, cnt = 0;
    bool flag = true;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j != p) {
            int t = dfs(j, u, res);
            if (child == -1) child = t;
            else if (child != t) flag = false;
            cnt += t;
        }
    }
    if (flag) res++;
    return cnt + 1;
}

class Solution {
public:
    int countGoodNodes(vector<vector<int>> &edges) {
        int n = edges.size() + 1, res = 0;
        memset(h, -1, sizeof(int) * n), idx = 0;
        for (auto &edge: edges) {
            add(edge[0], edge[1]);
            add(edge[1], edge[0]);
        }
        dfs(0, -1, res);
        return res;
    }
};