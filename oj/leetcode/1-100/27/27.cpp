#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int i = 0;
        for (int u = 0; u < nums.size(); u++) {
            if (nums[u] != val) nums[i++] = nums[u];
        }
        return i;
    }
};