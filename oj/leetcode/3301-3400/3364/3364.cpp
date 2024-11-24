#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSumSubarray(vector<int> &nums, int l, int r) {
        int n = static_cast<int>(nums.size());
        int s[n + 1];
        s[0] = 0;
        for (int i = 0; i < n; i++) {
            s[i + 1] = s[i] + nums[i];
        }
        int res = 1e9;
        multiset<int> S = {-1'000'000'000};
        for (int lo = 0, hi = 1; hi <= n; hi++) {
            if (hi >= l) {
                S.emplace(s[hi - l]);
                auto it = S.lower_bound(s[hi]);
                it--;
                res = min(res, s[hi] - *it);
                if (hi >= r) {
                    S.erase(S.find(s[lo]));
                    lo++;
                }
            }
        }
        return res >= 1e9 / 2 ? -1 : res;
    }
};