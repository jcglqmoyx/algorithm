#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int> &nums) {
        int res = 0;
        for (int last = 0, i = 0; i + 1 < nums.size(); i += 2) {
            int s = nums[i] + nums[i + 1];
            if (!last || s == last) res++;
            else break;
            last = s;
        }
        return res;
    }
};