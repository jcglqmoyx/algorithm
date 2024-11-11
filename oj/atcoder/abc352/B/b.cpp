#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

size_t n, m;
char s[N], t[N];

void solve() {
    scanf("%s%s", s, t);
    n = strlen(s), m = strlen(t);
    size_t i = 0, j = 0;
    while (i < n) {
        while (t[j] != s[i]) j++;
        printf("%zu ", j + 1);
        i++, j++;
    }
}

int main() {
    solve();
    return 0;
}