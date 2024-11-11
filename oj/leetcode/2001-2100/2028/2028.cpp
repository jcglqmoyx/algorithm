#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n) {
        int m = rolls.size(), s = accumulate(rolls.begin(), rolls.end(), 0);
        int diff = mean * (m + n) - s;
        vector<int> res;
        if (diff < n || diff > n * 6) return res;
        for (int i = n; i; i--) {
            int t = min(6, diff - (i - 1));
            res.emplace_back(t);
            diff -= t;
        }
        return res;
    }
};