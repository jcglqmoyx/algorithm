#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfPoints(vector<vector<int>> &nums) {
        int s[102]{};
        for (auto &range: nums) {
            s[range[0]]++;
            s[range[1] + 1]--;
        }
        int res = 0;
        for (int i = 1; i <= 100; i++) {
            s[i] += s[i - 1];
            res += s[i] > 0 ? 1 : 0;
        }
        return res;
    }
};