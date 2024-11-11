#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int> &nums, int k) {
        int n = nums.size(), res = 0, s[n + 2];
        memset(s, 0, sizeof s);
        for (int i = 1; i <= n; i++) {
            s[i] += s[i - 1];
            int x = (nums[i - 1] + s[i]) & 1;
            if (x == 0) {
                if (i + k - 1 > n) {
                    return -1;
                }
                s[i]++;
                s[i + k]--;
                res++;
            }
        }
        return res;
    }
};