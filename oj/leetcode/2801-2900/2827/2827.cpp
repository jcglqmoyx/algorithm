#include <bits/stdc++.h>

using namespace std;

class Solution {
    int calc(int high, int k) {
        auto s = to_string(high);
        auto n = s.length();
        int memo[n][k][n * 2 + 1];
        memset(memo, -1, sizeof(memo));
        function<int(int, int, int, bool, bool)> dfs;
        dfs = [&](int i, int mod, int diff, bool is_num, bool is_limited) -> int {
            if (i == n) {
                return !mod && diff == n && is_num;
            }
            if (is_num && !is_limited && memo[i][mod][diff] != -1) {
                return memo[i][mod][diff];
            }
            int res = 0;
            if (!is_num) {
                res = dfs(i + 1, mod, diff, is_num, false);
            }
            int up = is_limited ? s[i] - '0' : 9;
            for (int d = 1 - is_num; d <= up; d++) {
                res += dfs(i + 1, (mod * 10 + d) % k, diff + (d & 1 ? 1 : -1), true, is_limited && d == up);
            }
            if (is_num && !is_limited) {
                memo[i][mod][diff] = res;
            }
            return res;
        };
        return dfs(0, 0, n, false, true);
    }

public:
    int numberOfBeautifulIntegers(int low, int high, int k) {
        return calc(high, k) - calc(low - 1, k);
    }
};