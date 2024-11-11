#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumRobots(vector<int> &chargeTimes, vector<int> &runningCosts, long long budget) {
        multiset<int> s;
        long long cost = 0;
        int res = 0;
        for (int i = 0, j = 0; j < runningCosts.size(); j++) {
            s.emplace(chargeTimes[j]);
            cost += runningCosts[j];
            while (i <= j && *s.rbegin() + (j - i + 1LL) * cost > budget) {
                s.erase(s.find(chargeTimes[i]));
                cost -= runningCosts[i];
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};