#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countQuadruplets(vector<int> &nums) {
        using ll = long long;
        auto n = nums.size();
        vector<vector<int>> l(n, vector<int>(n + 1));
        vector<vector<int>> r(n + 1, vector<int>(n + 1));
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i) l[i][j] = l[i - 1][j];
                if (nums[i] < j) l[i][j]++;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= n; j++) {
                r[i][j] = r[i + 1][j];
                if (nums[i] > j) r[i][j]++;
            }
        }
        ll res = 0;
        for (int i = 1; i + 2 < n; i++) {
            for (int j = i + 1; j + 1 < n; j++) {
                if (nums[i] > nums[j]) {
                    res += l[i - 1][nums[j]] * r[j + 1][nums[i]];
                }
            }
        }
        return res;
    }
};