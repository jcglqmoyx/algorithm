#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumXORSum(vector<int> &nums1, vector<int> &nums2) {
        int n = static_cast<int>(nums1.size());
        int f[1 << n];
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for (int i = 1; i < 1 << n; i++) {
            int cnt = __builtin_popcount(i);
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) {
                    f[i] = min(f[i], f[i ^ (1 << j)] + (nums1[cnt - 1] ^ nums2[j]));
                }
            }
        }
        return f[(1 << n) - 1];
    }
};