#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int countWays(vector<vector<int>>&ranges) {
        ranges::sort(ranges.begin(), ranges.end());
        int res = 1;
        for (int i = 0; i < ranges.size(); i++) {
            int end = ranges[i][1], j = i + 1;
            while (j < ranges.size() && ranges[j][0] <= end) end = max(end, ranges[j][1]), j++;
            res = res * 2 % 1000000007;
            i = j - 1;
        }
        return res;
    }
};
