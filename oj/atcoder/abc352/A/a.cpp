#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x, y, z;
    scanf("%d%d%d%d", &n, &x, &y, &z);
    if (x > y) swap(x, y);
    if (x <= z && z <= y) puts("Yes");
    else puts("No");
}

int main() {
    solve();
    return 0;
}