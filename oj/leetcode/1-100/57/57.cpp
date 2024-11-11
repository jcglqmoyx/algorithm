#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        vector<vector<int>> res;
        if (intervals.empty()) {
            res.emplace_back(newInterval);
            return res;
        }
        auto n = intervals.size();
        if (newInterval[0] < intervals[0][0]) {
            intervals.insert(intervals.begin(), newInterval);
        } else {
            for (int i = 0; i < n; i++) {
                if (newInterval[0] >= intervals[i][0] && (i == n - 1 || newInterval[0] <= intervals[i + 1][0])) {
                    intervals.insert(intervals.begin() + i + 1, newInterval);
                    break;
                }
            }
        }
        n++;
        for (int i = 0; i < n; i++) {
            int start = intervals[i][0], end = intervals[i][1];
            int j = i + 1;
            while (j < n && intervals[j][0] <= end) {
                end = max(end, intervals[j][1]);
                j++;
            }
            res.push_back({start, end});
            i = j - 1;
        }
        return res;
    }
};