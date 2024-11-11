#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumTotalSum(vector<int> &maximumHeight) {
        sort(maximumHeight.begin(), maximumHeight.end());
        long long res = 0;
        for (int last = 2e9, i = maximumHeight.size() - 1; i >= 0; i--) {
            if (maximumHeight[i] < i + 1) return -1;
            last = min(last - 1, maximumHeight[i]);
            res += last;
        }
        return res;
    }
};