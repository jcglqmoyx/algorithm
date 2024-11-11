#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>> &composition, vector<int> &stock, vector<int> &cost) {
        int res = 0;
        for (int i = 0; i < k; i++) {
            int l = 0, r = 1e9;
            while (l < r) {
                long long t = budget;
                int mid = (l + r + 1) / 2;
                for (int j = 0; j < n; j++) {
                    if (mid * 1LL * composition[i][j] > stock[j]) t -= (mid * 1LL * composition[i][j] - stock[j]) * cost[j];
                }
                if (t >= 0) l = mid;
                else r = mid - 1;
            }
            res = max(res, l);
        }
        return res;
    }
};