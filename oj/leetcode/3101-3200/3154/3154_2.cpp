int c[32][32];

int init = []() {
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) c[i][j] = 1;
            else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    return 0;
}();

class Solution {
public:
    int waysToReachStair(int k) {
        int res = 0;
        for (int i = k > 1 ? 32 - __builtin_clz(k - 1) : 0; (1 << i) - k <= i + 1; i++) {
            res += c[i + 1][(1 << i) - k];
        }
        return res;
    }
};