#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int waysToReachStair(int k) {
        unordered_map<string, int> memo;
        function<int(int, int, bool)> dp = [&](int val, int jump, bool dec) -> int {
            string s = to_string(val) + " " + to_string(jump) + " " + (dec ? to_string(1) : to_string(0));
            if (memo.contains(s)) return memo[s];
            memo[s] = val == k;
            if (!dec && val) memo[s] += dp(val - 1, jump, true);
            if (val + (1 << jump) <= k + 1) memo[s] += dp(val + (1 << jump), jump + 1, false);
            return memo[s];
        };
        return dp(1, 0, false);
    }
};