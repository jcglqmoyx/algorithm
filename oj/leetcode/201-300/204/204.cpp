const int N = 5000000, M = 348515;

bool st[N];
int p[M], idx;

int init = []() {
    idx = 0;
    for (int i = 2; i < N; i++) {
        if (!st[i]) p[++idx] = i;
        for (int j = 1; p[j] * i < N; j++) {
            st[p[j] * i] = true;
            if (i % p[j] == 0) break;
        }
    }
    return 0;
}();

class Solution {
public:
    int countPrimes(int n) {
        int l = 0, r = idx;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (p[mid] < n) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};