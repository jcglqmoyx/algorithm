#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int> &nums) {
        int s = 0;
        for (int x: nums) {
            s |= x;
        }
        return s << (nums.size() - 1);
    }
};