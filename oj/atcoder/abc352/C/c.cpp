#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int N = 200010;

int n;

void solve() {
    scanf("%d", &n);
    LL s = 0;
    int mx = 0;
    for (int a, b, i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        mx = max(mx, b - a);
        s += a;
    }
    printf("%lld\n", s + mx);
}

int main() {
    solve();
    return 0;
}