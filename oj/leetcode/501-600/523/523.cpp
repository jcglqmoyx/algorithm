#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        long long s = 0;
        for (int i = 0; i < nums.size(); i++) {
            s = (s + nums[i]) % k;
            if (mp.contains(s)) {
                if (i - mp[s] > 1) {
                    return true;
                }
            } else {
                mp[s] = i;
            }
        }
        return false;
    }
};