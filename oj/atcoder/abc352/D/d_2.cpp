#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int N = 200010;

int n, k;
int p[N];
int q1[N];
int q2[N];

void solve() {
    scanf("%d%d", &n, &k);
    for (int x, i = 1; i <= n; i++) {
        scanf("%d", &x);
        p[x] = i;
    }
    if (k == 1) {
        puts("0");
        return;
    }
    int res = n;
    int hh1 = 0, tt1 = -1;
    int hh2 = 0, tt2 = -1;
    for (int r = 1; r <= n; r++) {
        while (hh1 <= tt1 && q1[hh1] <= r - k) hh1++;
        while (hh2 <= tt2 && q2[hh2] <= r - k) hh2++;
        while (hh1 <= tt1 && p[q1[tt1]] <= p[r]) tt1--;
        while (hh2 <= tt2 && p[q2[tt2]] >= p[r]) tt2--;
        q1[++tt1] = r;
        q2[++tt2] = r;
        if (r >= k) {
            res = min(res, p[q1[hh1]] - p[q2[hh2]]);
        }
    }
    printf("%d\n", res);
}

int main() {
    solve();
    return 0;
}