#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> mostCompetitive(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n; i++) {
            while (!res.empty() && k - (int) res.size() < n - i && res.back() > nums[i]) res.pop_back();
            res.emplace_back(nums[i]);
        }
        res.resize(k);
        return res;
    }
};