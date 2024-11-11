#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSessions(vector<int> &tasks, int sessionTime) {
        auto n = tasks.size();
        int s[1 << n];
        s[0] = 0;
        for (int i = 1; i < 1 << n; i++) {
            int lb = i & -i;
            s[i] = s[i ^ lb] + tasks[__builtin_ctz(i)];
        }
        int f[1 << n];
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for (int i = 1; i < 1 << n; i++) {
            for (int j = i; j; j = (j - 1) & i) {
                if (s[j] <= sessionTime) {
                    f[i] = min(f[i], f[i ^ j] + 1);
                }
            }
        }
        return f[(1 << n) - 1];
    }
};