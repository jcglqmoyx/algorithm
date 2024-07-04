#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList) {
        auto check = [&](auto &a, auto &b) {
            return !(a[0] > b[1] || b[0] > a[1]);
        };
        auto n = firstList.size(), m = secondList.size();
        vector<vector<int>> res;
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (check(firstList[i], secondList[j])) {
                res.push_back({max(firstList[i][0], secondList[j][0]), min(firstList[i][1], secondList[j][1])});
            }
            if (firstList[i][1] > secondList[j][1]) j++;
            else i++;
        }
        return res;
    }
};