#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canMakeSquare(vector<vector<char>> &grid) {
        for (int i = 0; i <= 1; i++) {
            for (int j = 0; j <= 1; j++) {
                int b = 0, w = 0;
                for (int x = i; x < i + 2; x++) {
                    for (int y = j; y < j + 2; y++) {
                        if (grid[x][y] == 'W') w++;
                        else b++;
                    }
                }
                if (b >= 3 || w >= 3) return true;
            }
        }
        return false;
    }
};