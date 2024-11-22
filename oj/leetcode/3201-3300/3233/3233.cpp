#include <bits/stdc++.h>

using namespace std;

const int N = 35010;

bool st[N];
int prime[N], idx;

int init = [] {
    for (int i = 2; i < N; i++) {
        st[1] = true;
        if (!st[i]) prime[idx++] = i;
        for (int j = 0; prime[j] * i < N; j++) {
            st[prime[j] * i] = true;
            if (i % prime[j] == 0) break;
        }
    }
    return 0;
}();

class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int x = sqrt(r), res = 0;
        for (int i = sqrt(l); i <= x; i++) {
            if (i * i >= l && !st[i]) {
                res++;
            }
        }
        return r - l + 1 - res;
    }
};