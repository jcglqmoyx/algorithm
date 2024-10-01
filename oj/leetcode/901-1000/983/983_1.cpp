#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mincostTickets(vector<int> &days, vector<int> &costs) {
        auto n = days.size();
        int f[n + 1];
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            f[i] = f[i - 1] + costs[0];
            int j = i;
            while (j && days[i - 1] - days[j - 1] <= 0) j--;
            f[i] = min(f[i], f[j] + costs[0]);
            while (j && days[i - 1] - days[j - 1] <= 6) j--;
            f[i] = min(f[i], f[j] + costs[1]);
            while (j && days[i - 1] - days[j - 1] <= 29) j--;
            f[i] = min(f[i], f[j] + costs[2]);
        }
        return f[n];
    }
};