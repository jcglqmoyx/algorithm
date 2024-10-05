#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumTime(vector<int> &time, int totalTrips) {
        long long l = 1, r = time[0] * 1LL * totalTrips;
        while (l < r) {
            auto mid = (l + r) >> 1;
            auto s = 0LL;
            for (int x: time) {
                s += mid / x;
            }
            if (s >= totalTrips) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};