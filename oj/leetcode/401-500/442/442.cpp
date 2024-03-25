#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static vector<int> findDuplicates(vector<int>&nums) {
        vector<int> res;
        for (int x: nums) {
            x = abs(x);
            if (nums[x - 1] < 0) res.push_back(abs(x));
            else nums[x - 1] = -nums[x - 1];
        }
        return res;
    }
};
