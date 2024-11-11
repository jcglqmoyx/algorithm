#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumRobots(vector<int> &chargeTimes, vector<int> &runningCosts, long long budget) {
        auto n = chargeTimes.size();
        int q[n], res = 0;
        long long c = 0;
        for (int hh = 0, tt = -1, i = 0, j = 0; j < n; j++) {
            while (hh <= tt && chargeTimes[j] >= chargeTimes[q[tt]]) tt--;
            q[++tt] = j;
            c += runningCosts[j];
            while (hh <= tt && chargeTimes[q[hh]] + (j - i + 1) * c > budget) {
                c -= runningCosts[i];
                i++;
                if (q[hh] < i) hh++;
            }
            if (hh <= tt) res = max(res, j - i + 1);
        }
        return res;
    }
};