#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int> &nums, int k) {
        int res = 0;
        for (int &x: nums) {
            x %= k;
        }
        int f[k];
        for (int i = 0; i < k; i++) {
            memset(f, 0, sizeof f);
            for (int x: nums) {
                f[x] = f[(i - x + k) % k] + 1;
                res = max(res, f[x]);
            }
        }
        return res;
    }
};