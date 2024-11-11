#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int> &values) {
        int mx = INT32_MIN, res = 0;
        for (int i = 0; i < values.size(); i++) {
            res = max(res, mx + values[i] - i);
            mx = max(mx, values[i] + i);
        }
        return res;
    }
};