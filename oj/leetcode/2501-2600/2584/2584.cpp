#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findValidSplit(vector<int> &nums) {
        unordered_map<int, pair<int, int>> p;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int j = 2; j * j <= x; j++) {
                if (x % j == 0) {
                    if (p.contains(j)) {
                        p[j].second = i;
                    } else {
                        p[j] = {i, i};
                    }
                    while (x % j == 0) {
                        x /= j;
                    }
                }
            }
            if (x > 1) {
                if (p.contains(x)) {
                    p[x].second = i;
                } else {
                    p[x] = {i, i};
                }
            }
        }

        fill(nums.begin(), nums.end(), 0);
        for (auto &[_, range]: p) {
            nums[range.first] = max(nums[range.first], range.second);
        }
        for (int i = 0, end = -1; i < n - 1; i++) {
            end = max(end, nums[i]);
            if (i >= end) return i;
        }
        return -1;
    }
};