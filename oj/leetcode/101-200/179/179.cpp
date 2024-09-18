#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int> &nums) {
        auto n = nums.size();
        vector<string> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = to_string(nums[i]);
        }
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a + b > b + a;
        });
        string res;
        for (auto &s: v) {
            res += s;
        }
        int i = 0;
        while (i + 1 < res.size() && res[i] == '0') i++;
        return res.substr(i);
    }
};