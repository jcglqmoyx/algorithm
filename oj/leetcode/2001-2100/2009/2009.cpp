#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int> &nums) {
        int n = nums.size(), res = n - 1;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int m = nums.size();
        for (int i = 0, j = 0; i < m; i++) {
            while (j < m && nums[j] < nums[i] + n - 1) j++;
            res = min(res, n - (j - i));
        }
        return res;
    }
};