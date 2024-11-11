#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScore(int n, int k, vector<vector<int>> &stayScore, vector<vector<int>> &travelScore) {
        int f[k + 1][n];
        memset(f, 0, sizeof f);
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < n; j++) {
                for (int prev = 0; prev < n; prev++) {
                    if (prev == j) f[i][j] = max(f[i][j], f[i - 1][prev] + stayScore[i - 1][j]);
                    else f[i][j] = max(f[i][j], f[i - 1][prev] + travelScore[prev][j]);
                }
            }
        }
        return *max_element(f[k], f[k] + n);
    }
};