#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxGoodNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end(), [](int x, int y) {
            return (x << (__lg(y) + 1) | y) > (y << (__lg(x) + 1) | x);
        });
        int res = 0;
        for (int x: nums) {
            res = res << (__lg(x) + 1) | x;
        }
        return res;
    }
};