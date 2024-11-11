#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = 0;
        for (int i = 0, j = n / 2; i < n / 2 && j < n; j++) {
            if (nums[i] * 2 <= nums[j]) res += 2, i++;
        }
        return res;
    }
};