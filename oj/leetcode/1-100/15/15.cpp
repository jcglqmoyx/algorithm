#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        auto n = nums.size();
        for (int a = 0; a + 2 < n; a++) {
            if (a && nums[a] == nums[a - 1]) continue;
            int s = -nums[a];
            if (nums[a + 1] + nums[a + 2] > s || nums[n - 1] + nums[n - 2] < s) continue;
            int b = a + 1, c = n - 1;
            while (b < c) {
                int t = nums[b] + nums[c];
                if (t < s) b++;
                else if (t > s) c--;
                else {
                    res.push_back({nums[a], nums[b], nums[c]});
                    while (b < c && nums[b] == nums[b + 1]) b++;
                    b++;
                }
            }
        }
        return res;
    }
};