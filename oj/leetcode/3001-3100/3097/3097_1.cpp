#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int> &nums, int k) {
        int n = nums.size();
        int cnt[n + 1][32];
        memset(cnt, 0, sizeof cnt);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 32; j++) {
                cnt[i][j] = cnt[i - 1][j];
            }
            for (int j = 0; j < 32; j++) {
                if (nums[i - 1] >> j & 1) cnt[i][j]++;
            }
        }

        auto check = [&](int mid) {
            for (int i = 1; i + mid - 1 <= n; i++) {
                int j = i + mid - 1;
                int x = 0;
                for (int u = 0; u < 32; u++) {
                    if (cnt[j][u] - cnt[i - 1][u]) x |= 1 << u;
                }
                if (x >= k) return true;
            }
            return false;
        };

        int l = 1, r = n + 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        return l == n + 1 ? -1 : l;
    }
};