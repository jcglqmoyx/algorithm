#include <bits/stdc++.h>

using namespace std;

class TreeAncestor {
    int m;
    vector<vector<int>> f;
public:
    TreeAncestor(int n, vector<int> &parent) {
        m = (int) log2(n);
        f.resize(n, vector<int>(m + 1, -1));
        for (int i = 0; i < n; i++) f[i][0] = parent[i];
        for (int j = 1; j <= m; j++) {
            for (int i = 0; i < n; i++) {
                if (f[i][j - 1] != -1) {
                    f[i][j] = f[f[i][j - 1]][j - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int i = m; i >= 0; i--) {
            if (k >> i & 1) {
                node = f[node][i];
                if (node == -1) {
                    return -1;
                }
            }
        }
        return node;
    }
};