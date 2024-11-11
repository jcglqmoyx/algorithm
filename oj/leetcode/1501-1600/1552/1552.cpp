#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int> &position, int m) {
        sort(position.begin(), position.end());
        auto n = position.size();
        auto check = [&](int mid) {
            int cnt = 1, prev = position[0];
            for (int i = 1; i < n; i++) {
                if (position[i] - prev >= mid) {
                    prev = position[i];
                    cnt++;
                }
            }
            return cnt >= m;
        };
        int l = (position[n - 1] - position[0]) / (m - 1), r = position[n - 1] - position[0] - (m - 2);
        for (int i = 1; i < n; i++) l = min(l, position[i] - position[i - 1]);
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};