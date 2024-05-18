#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDivScore(vector<int> &nums, vector<int> &divisors) {
        int res = 1e9, t = 0;
        for (int x: divisors) {
            int cnt = 0;
            for (int y: nums) {
                if (y % x == 0) cnt++;
            }
            if (cnt > t) {
                res = x, t = cnt;
            } else if (cnt == t && res > x) {
                res = x;
            }
        }
        return res;
    }
};