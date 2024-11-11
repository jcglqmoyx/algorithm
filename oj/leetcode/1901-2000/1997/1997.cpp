#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int firstDayBeenInAllRooms(const vector<int> &nextVisit) {
        static constexpr int MOD = 1e9 + 7;
        auto n = nextVisit.size();
        int f[n][2]; // f[i][0]: the first day to visit room i; f[i][1]: the second day to visit room i
        memset(f, 0, sizeof f);
        f[0][1] = 1;
        for (int i = 1; i < n; i++) {
            f[i][0] = (f[i - 1][1] + 1) % MOD;
            if (nextVisit[i] == i) f[i][1] = f[i][0] + 1;
            else f[i][1] = f[i][0] + ((f[i][0] - f[nextVisit[i]][0] + MOD) % MOD) + 1;
            f[i][1] %= MOD;
        }
        return f[n - 1][0];
    }
};