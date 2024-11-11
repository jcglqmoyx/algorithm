#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDays(int n) {
        unordered_map<int, int> mp;
        function<int(int)> dp = [&](int x) -> int {
            if (x <= 1) return x;
            if (mp.contains(x)) return mp[x];
            return mp[x] = min(x % 3 + dp(x / 3), x % 2 + dp(x / 2)) + 1;
        };
        return dp(n);
    }
};