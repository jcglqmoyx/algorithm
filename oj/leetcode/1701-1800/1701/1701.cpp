#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>> &customers) {
        double s = 0;
        int start = 0;
        for (auto &c: customers) {
            if (c[0] > start) start = c[0];
            s += start + c[1] - c[0];
            start += c[1];
        }
        return s / customers.size();
    }
};