#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDays(vector<int> &bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (n < (long long) m * k) return -1;
        auto check = [&](int mid) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (bloomDay[i] <= mid) {
                    int j = i + 1;
                    while (j < n && bloomDay[j] <= mid) j++;
                    cnt += (j - i) / k;
                    i = j - 1;
                }
            }
            return cnt >= m;
        };
        int l = 1, r = *max_element(bloomDay.begin(), bloomDay.end());
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};