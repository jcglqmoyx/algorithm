#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSpeedOnTime(vector<int> &dist, double hour) {
        int n = dist.size(), l = 1, r = 1e7 + 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            double tot = 0;
            for (int i = 0; i + 1 < n; i++) {
                tot += (dist[i] + mid - 1) / mid;
            }
            tot += dist.back() * 1.0 / mid;
            if (tot < hour || abs(tot - hour) < 1e-9) r = mid;
            else l = mid + 1;
        }
        return l == 1e7 + 1 ? -1 : l;
    }
};