#include <bits/stdc++.h>

using namespace std;

int power(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1) res = res * a;
        a = (long long) a * a;
        n >>= 1;
    }
    return res;
}

class Solution {
public:
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier) {
        if (multiplier == 1) {
            return nums;
        }
        auto n = nums.size();
        int mx = 0;
        set<pair<int, int>> s;
        for (int i = 0; i < n; i++) {
            s.emplace(nums[i], i);
            mx = max(mx, nums[i]);
        }
        int op = 0;
        while (op < k) {
            int mn = s.begin()->first, idx = s.begin()->second;
            s.erase(s.begin());
            if ((long long) mn * multiplier <= mx) {
                mn *= multiplier;
                op++;
                s.emplace(mn, idx);
            } else {
                s.emplace(mn, idx);
                break;
            }
        }
        for (auto it: s) {
            nums[it.second] = it.first;
        }
        k -= op;
        if (!k) return nums;
        int round = k / n;
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] * power(multiplier, round);
        }
        k %= n;
        while (k--) {
            auto idx = s.begin()->second;
            s.erase(s.begin());
            nums[idx] = nums[idx] * multiplier;
        }
        return nums;
    }
};