#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(int n, vector<int> &cuts) {
        cuts.emplace_back(0);
        cuts.emplace_back(n);
        sort(cuts.begin(), cuts.end());
        int m = static_cast<int> (cuts.size());
        int f[m][m];
        memset(f, 0x3f, sizeof f);
        for (int i = 0; i + 1 < m; i++) {
            f[i][i + 1] = 0;
        }
        for (int len = 3; len <= m; len++) {
            for (int l = 0; l + len - 1 < m; l++) {
                int r = l + len - 1;
                for (int i = l + 1; i < r; i++) {
                    f[l][r] = min(f[l][r], f[l][i] + f[i][r] + cuts[r] - cuts[l]);
                }
            }
        }
        return f[0][m - 1];
    }
};