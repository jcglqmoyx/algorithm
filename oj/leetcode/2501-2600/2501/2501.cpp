#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSquareStreak(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int res = -1;
        unordered_map<int, int> map;
        for (int x: nums) {
            int st = sqrt(x);
            if (st * st == x && map.contains(st)) {
                map[x] = map[st] + 1;
                res = max(res, map[x]);
            } else {
                map[x] = 1;
            }
        }
        return res;
    }
};