#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (int i = 0; i < intervals.size(); i++) {
            int start = intervals[i][0], end = intervals[i][1];
            int j = i + 1;
            while (j < intervals.size() && intervals[j][0] <= end) {
                end = max(end, intervals[j][1]);
                j++;
            }
            res.push_back({start, end});
            i = j - 1;
        }
        return res;
    }
};