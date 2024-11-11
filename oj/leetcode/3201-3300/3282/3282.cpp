#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long findMaximumScore(vector<int> &nums) {
        using ll = long long;
        ll mx = nums[0], res = 0;
        for (int i = 1; i < nums.size(); i++) {
            res += mx;
            mx = max(mx, (ll) nums[i]);
        }
        return res;
    }
};