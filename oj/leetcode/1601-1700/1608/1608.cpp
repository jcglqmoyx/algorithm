#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int specialArray(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int x = nums.back(), i = n - 1; x; x--) {
            while (i >= 0 && nums[i] >= x) i--;
            if (n - i - 1 == x) return x;
        }
        return -1;
    }
};