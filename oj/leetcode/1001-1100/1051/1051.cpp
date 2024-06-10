#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int> &heights) {
        auto v = heights;
        sort(v.begin(), v.end());
        int res = 0;
        for (int i = 0; i < heights.size(); i++) {
            res += heights[i] != v[i];
        }
        return res;
    }
};