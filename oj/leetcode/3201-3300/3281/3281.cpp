#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxPossibleScore(vector<int> &start, int d) {
        auto n = start.size();
        sort(start.begin(), start.end());
        auto check = [&](long mid) {
            long x = start[0];
            for (int i = 1; i < n; i++) {
                long l = start[i], r = start[i] + d;
                if (x + mid > r) return false;
                x = max(x + mid, l);
            }
            return true;
        };

        long long l = 0, r = 2e9;
        while (l < r) {
            long long mid = (l + r + 1) >> 1;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};