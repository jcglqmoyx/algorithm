#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long incremovableSubarrayCount(vector<int> &nums) {
        nums.insert(nums.begin(), 0);
        nums.emplace_back(1e9 + 1);
        int n = nums.size();
        bool l[n];
        l[0] = true;
        for (int i = 1; i < n; i++) {
            l[i] = l[i - 1] & (nums[i] > nums[i - 1]);
        }
        if (l[n - 1]) {
            return (n - 1LL) * (n - 2LL) / 2;
        }

        bool r[n];
        r[n - 1] = true;
        for (int i = n - 2; i >= 0; i--) {
            r[i] = r[i + 1] & (nums[i] < nums[i + 1]);
        }
        long long res = 0;
        for (int j = 0, i = 1; i + 1 < n; i++) {
            if (r[i + 1]) {
                while (l[j + 1] && nums[j + 1] < nums[i + 1]) j++;
                res += j + 1;
            }
        }
        return res;
    }
};