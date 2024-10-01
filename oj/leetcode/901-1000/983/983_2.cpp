#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mincostTickets(vector<int> &days, vector<int> &costs) {
        auto n = days.size();
        int f[n + 1];
        f[0] = 0;
        for (int j = 0, k = 0, i = 1; i <= n; i++) {
            f[i] = f[i - 1] + costs[0];
            while (days[j] + 6 < days[i - 1]) j++;
            f[i] = min(f[i], f[j] + costs[1]);
            while (days[k] + 29 < days[i - 1]) k++;
            f[i] = min(f[i], f[k] + costs[2]);
        }
        return f[n];
    }
};