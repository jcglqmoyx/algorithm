#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubarray(vector<int> &nums, int p) {
        int mod = 0;
        for (int x: nums) {
            mod = (mod + x) % p;
        }
        if (!mod) return 0;
        unordered_map<int, int> map;
        map[0] = -1;
        int res = 1e8;
        for (int s = 0, i = 0; i < nums.size(); i++) {
            s = (s + nums[i]) % p;
            if (map.contains((s - mod + p) % p)) {
                res = min(res, i - map[(s - mod + p) % p]);
            }
            map[s] = i;
        }
        return res == 1e8 || res == nums.size() ? -1 : res;
    }
};