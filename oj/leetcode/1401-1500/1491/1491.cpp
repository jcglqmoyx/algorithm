#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double average(vector<int> &salary) {
        int mx = -1e9, mn = 1e9;
        double s = 0;
        for (int x: salary) {
            mx = max(mx, x);
            mn = min(mn, x);
            s += x;
        }
        return (s - mx - mn) / (salary.size() - 2);
    }
};