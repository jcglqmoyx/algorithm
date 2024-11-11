#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countGood(vector<int> &nums, int k) {
        long long res = 0;
        unordered_map<int, int> mp;
        for (int p = 0, l = 0, r = 0; r < nums.size(); r++) {
            mp[nums[r]]++;
            if (mp[nums[r]] > 1) p += mp[nums[r]] - 1;
            while (p >= k) {
                mp[nums[l]]--;
                int t = mp[nums[l]];
                if (t == 0) mp.erase(nums[l]);
                p -= t;
                l++;
            }
            res += l;
        }
        return res;
    }
};