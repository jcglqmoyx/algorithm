const int N = 10;

int a[N][N];

int init = []() {
    for (int i = 1; i < N; i++) {
        a[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            a[i][j] = a[i][j - 1] * (i - j + 1);
        }
    }
    return 0;
}();

class Solution {
public:
    int countSpecialNumbers(int n) {
        int v[10], idx = 0;
        while (n) v[idx++] = n % 10, n /= 10;
        int res = 0;
        for (int len = 1; len < idx; len++) {
            res += 9 * a[9][len - 1];
        }
        int used = 0;
        for (int i = idx - 1; i >= 0; i--) {
            int d = v[i];
            for (int j = (i == idx - 1 ? 1 : 0); j < d; j++) {
                if (!(used >> j & 1)) {
                    res += a[10 - (idx - i)][i];
                }
            }
            if (used >> d & 1) break;
            if (!i) res++;
            used |= 1 << d;
        }
        return res;
    }
};