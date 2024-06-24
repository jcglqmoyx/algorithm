#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int n = nums.size();
        vector<int> res(n);
        for (int i = 0; i < n - 1; i++) {
            nums.emplace_back(nums[i]);
        }
        stack<int> stk;
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!stk.empty() && stk.top() <= nums[i]) stk.pop();
            if (i < n) {
                res[i] = stk.empty() ? -1 : stk.top();
            }
            stk.emplace(nums[i]);
        }
        return res;
    }
};