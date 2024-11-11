#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long numberOfSubarrays(vector<int> &nums) {
        long long res = nums.size();
        stack<pair<int, int>> stk;
        stk.emplace(INT32_MAX, 0);
        for (int x: nums) {
            while (x > stk.top().first) stk.pop();
            if (x == stk.top().first) res += stk.top().second++;
            else stk.emplace(x, 1);
        }
        return res;
    }
};