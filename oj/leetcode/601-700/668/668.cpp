#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        auto check = [&](int mid) {
            int cnt = 0;
            for (int i = 1; i <= min(m, mid); i++) {
                int t = min(n, mid / i);
                if (t == 0) break;
                cnt += t;
            }
            return cnt >= k;
        };
        int l = 1, r = m * n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};