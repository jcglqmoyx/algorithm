#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDistance(vector<vector<int>> &points) {
        multiset<int> s[2];
        for (auto &p: points) {
            s[0].insert(p[0] - p[1]);
            s[1].insert(p[0] + p[1]);
        }
        int res = 1e9;
        for (auto &p: points) {
            s[0].erase(s[0].find(p[0] - p[1]));
            s[1].erase(s[1].find(p[0] + p[1]));
            int t = max(*s[0].rbegin() - *s[0].begin(), *s[1].rbegin() - *s[1].begin());
            res = min(res, t);
            s[0].insert(p[0] - p[1]);
            s[1].insert(p[0] + p[1]);
        }
        return res;
    }
};