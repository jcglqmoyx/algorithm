#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxK(vector<int> &nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = -1;
        for (auto x: s) {
            if (x > 0 && s.contains(-x)) {
                res = max(res, x);
            }
        }
        return res;
    }
};