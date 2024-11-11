#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static long long countSubarrays(vector<int> &nums, int k) {
        long long res = 0;
        const int mx = *ranges::max_element(nums.begin(), nums.end());
        for (int cnt = 0, l = 0, r = 0; r < nums.size(); r++) {
            if (nums[r] == mx) {
                cnt++;
                while (cnt >= k) {
                    if (nums[l] == mx) cnt--;
                    l++;
                }
            }
            res += l;
        }
        return res;
    }
};
