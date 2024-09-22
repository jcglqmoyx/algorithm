#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int> &workerTimes) {
        using ll = long long;
        auto check = [&](ll mid) {
            int s = 0;
            for (int x: workerTimes) {
                s += (sqrt((8LL * mid) / x + 1LL) - 1) / 2;
            }
            return s >= mountainHeight;
        };
        ll l = 0, r = ranges::max(workerTimes) * 1LL * mountainHeight * (mountainHeight + 1) / 2;
        while (l < r) {
            ll mid = (l + r) >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};