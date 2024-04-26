#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>> &grid) {
        int a1 = 0, b1 = 0, idx1 = -1, f;
        for (int i = 0; i < grid.size(); i++) {
            int a2 = 1e9, b2 = 1e9, idx2;
            for (int j = 0; j < grid.size(); j++) {
                if (j != idx1) f = a1 + grid[i][j];
                else f = b1 + grid[i][j];
                if (f < a2) b2 = a2, a2 = f, idx2 = j;
                else if (f < b2) b2 = f;
            }
            a1 = a2, b1 = b2, idx1 = idx2;
        }
        return a1;
    }
};