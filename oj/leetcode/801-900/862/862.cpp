#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int> &nums, int k) {
        int n = static_cast<int> (nums.size());
        long long s[n + 1];
        s[0] = 0;
        int q[n + 1], hh = 0, tt = -1;
        q[++tt] = 0;
        int res = n + 1;
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + nums[i - 1];
            while (hh <= tt && s[q[tt]] >= s[i]) {
                tt--;
            }
            q[++tt] = i;
            while (hh <= tt && s[i] - s[q[hh]] >= k) {
                res = min(res, i - q[hh]);
                hh++;
            }
        }
        return res == n + 1 ? -1 : res;
    }
};