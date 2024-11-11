#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int> &nums, int k) {
        unordered_map<int, vector<int>> f;
        vector<array<int, 3>> mx(k + 1);
        for (int x: nums) {
            if (!f.contains(x)) f[x] = vector<int>(k + 1);
            for (int i = 0; i <= k; i++) {
                f[x][i]++;

                if (i) {
                    int first = mx[i - 1][0], first_number = mx[i - 1][1], second = mx[i - 1][2];
                    if (x == first_number) {
                        f[x][i] = max(f[x][i], second + 1);
                    } else {
                        f[x][i] = max(f[x][i], first + 1);
                    }
                }

                if (f[x][i] > mx[i][0]) {
                    mx[i][2] = mx[i][0];

                    mx[i][0] = f[x][i];
                    mx[i][1] = x;
                } else if (f[x][i] > mx[i][2]) {
                    mx[i][2] = f[x][i];
                }
            }
        }
        return mx[k][0];
    }
};