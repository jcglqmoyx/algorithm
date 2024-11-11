#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int> &nums, int k, int numOperations) {
        map<int, int> diff;
        unordered_map<int, int> cnt;
        for (int x: nums) {
            cnt[x]++;
            diff[x];
            diff[x - k]++;
            diff[x + k + 1]--;
        }
        int res = 0, sum = 0;
        for (auto &[x, v]: diff) {
            sum += v;
            res = max(res, min(sum, cnt[x] + numOperations));
        }
        return res;
    }
};