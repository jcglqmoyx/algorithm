#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long numberOfWeeks(vector<int> &milestones) {
        int mx = 0;
        long long res = 0;
        for (int x: milestones) {
            mx = max(mx, x);
            res += x;
        }
        res -= mx;
        res += min(res + 1, (long long) mx);
        return res;
    }
};