#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int> &nums, int limit) {
        int res = 0;
        deque<int> q1, q2;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            while (!q1.empty() && nums[q1.back()] >= nums[r]) q1.pop_back();
            q1.emplace_back(r);
            while (!q2.empty() && nums[q2.back()] <= nums[r]) q2.pop_back();
            q2.emplace_back(r);
            while (!q1.empty() && !q2.empty() && nums[q2.front()] - nums[q1.front()] > limit) {
                if (q1.front() == l) q1.pop_front();
                if (q2.front() == l) q2.pop_front();
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};