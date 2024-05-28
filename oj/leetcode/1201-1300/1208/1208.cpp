#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int res = 0, n = s.size();
        for (int cost = 0, l = 0, r = 0; r < n; r++) {
            cost += abs(t[r] - s[r]);
            while (cost > maxCost) {
                cost -= abs(t[l] - s[l]);
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};