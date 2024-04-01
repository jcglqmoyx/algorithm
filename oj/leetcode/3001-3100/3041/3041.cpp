#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int maxSelectedElements(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> f;
        for (int x: nums) {
            f[x + 1] = f[x] + 1;
            f[x] = f[x - 1] + 1;
        }
        int res = 0;
        for (auto &[_, v]: f) {
            res = max(res, v);
        }
        return res;
    }
};