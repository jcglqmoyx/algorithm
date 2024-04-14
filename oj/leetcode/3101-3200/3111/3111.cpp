#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>> &points, int w) {
        sort(points.begin(), points.end(), [](const auto &a, const auto &b) {
            return a[0] < b[0];
        });
        int res = 0, last = -1;
        for (auto &p: points) {
            if (p[0] > last) res++, last = p[0] + w;
        }
        return res;
    }
};