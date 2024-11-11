#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMinDifference(vector<string> &timePoints) {
        auto n = timePoints.size();
        int v[n];
        for (int i = 0; i < n; i++) {
            v[i] = stoi(timePoints[i].substr(0, 2)) * 60 + stoi(timePoints[i].substr(3));
        }
        sort(v, v + n);
        int res = 1440;
        for (int i = 1; i < n; i++) {
            res = min(res, v[i] - v[i - 1]);
        }
        res = min(res, 1440 - v[n - 1] + v[0]);
        return res;
    }
};