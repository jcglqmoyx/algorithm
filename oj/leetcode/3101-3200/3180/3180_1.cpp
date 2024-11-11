#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxTotalReward(vector<int> &rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        int mx = rewardValues.back();
        bool f[mx * 2];
        memset(f, 0, sizeof f);
        f[0] = true;
        for (int x: rewardValues) {
            for (int j = x * 2 - 1; j >= x; j--) {
                f[j] |= f[j - x];
            }
        }
        for (int i = mx * 2 - 1; i; i--) {
            if (f[i]) {
                return i;
            }
        }
        return -1;
    }
};