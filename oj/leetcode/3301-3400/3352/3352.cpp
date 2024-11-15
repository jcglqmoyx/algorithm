#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 805;

int op[N];
int comb[N][N];

int init = []() {
    for (int i = 1; i < N; i++) {
        int x = i;
        while (x != 1) {
            x = __builtin_popcount(x);
            op[i]++;
            if (op[x]) {
                op[i] += op[x];
                break;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
        }
    }
    return 0;
}();

class Solution {
public:
    int countKReducibleNumbers(string s, int k) {
        int n = static_cast<int>(s.size());
        if (n == 1) return 0;
        int res = 0;
        for (int i = 1; i < n; i++) {
            if (op[i] + 1 <= k) {
                res = (res + comb[n - 1][i]) % MOD;
            }
        }
        for (int cnt = s[0] == '1', i = 1; i < n; i++) {
            if (s[i] == '1') {
                for (int j = 0; j <= n - i - 1; j++) {
                    if (op[cnt + j] + 1 <= k) {
                        res = (res + comb[n - i - 1][j]) % MOD;
                    }
                }
                cnt++;
            }
        }
        return res;
    }
};