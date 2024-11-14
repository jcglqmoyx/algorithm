#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimizedMaximum(int n, vector<int> &quantities) {
        int l = (int) ((accumulate(quantities.begin(), quantities.end(), 0LL) + n - 1) / n);
        int r = *max_element(quantities.begin(), quantities.end());
        auto check = [&](int mid) {
            int i = 0, j = 0, m = static_cast<int>(quantities.size()), x;
            for (; j < m; j++) {
                x = quantities[j];
                while (i < n && x) {
                    x -= min(x, mid);
                    i++;
                }
            }
            return i <= n && !x;
        };
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};