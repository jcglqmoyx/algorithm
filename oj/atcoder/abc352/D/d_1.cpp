/**
 * N*logN
 */
#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int N = 200010;

int n, k;
int p[N];

void solve() {
    scanf("%d%d", &n, &k);
    for (int x, i = 1; i <= n; i++) {
        scanf("%d", &x);
        p[x] = i;
    }
    int res = n;
    set<int> s;
    for (int l = 1, r = 1; r <= n; r++) {
        s.insert(p[r]);
        if (r >= k) {
            res = min(res, *s.rbegin() - *s.begin());
            s.erase(p[l]);
            l++;
        }
    }
    printf("%d\n", res);
}

int main() {
    solve();
    return 0;
}