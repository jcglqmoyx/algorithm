#include <bits/stdc++.h>

using namespace std;

class NumArray {
    size_t n;
    vector<int> s;

public:
    explicit NumArray(const vector<int>&nums) {
        n = nums.size();
        s.resize(n + 1);
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
    }

    int sumRange(int left, int right) {
        return s[right + 1] - s[left];
    }
};
