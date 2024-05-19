#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long sumDigitDifferences(vector<int> &nums) {
        int n = to_string(nums[0]).size();
        long long cnt[n][10];
        memset(cnt, 0, sizeof cnt);
        for (int x: nums) {
            int i = 0;
            while (x) {
                cnt[i][x % 10]++;
                x /= 10;
                i++;
            }
        }
        long long res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 9; j++) {
                if (!cnt[i][j]) continue;
                for (int k = j + 1; k <= 9; k++) {
                    res += cnt[i][j] * cnt[i][k];
                }
            }
        }
        return res;
    }
};