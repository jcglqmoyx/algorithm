#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minPatches(vector<int> &nums, int n) {
        int res = 0;
        long long range = 0;
        for (int x: nums) {
            while (range < min(n, x) && range + 1 < x) {
                range += range + 1;
                res++;
            }
            if (range >= n) break;
            range += x;
        }
        while (range < n) {
            range += range + 1;
            res++;
        }
        return res;
    }
};