#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int> &nums) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                int j = i + 1;
                while (j < n && nums[j] == 0) j++;
                if (j == n) res++;
                else res += 2;
                i = j - 1;
            }
        }
        return res;
    }
};