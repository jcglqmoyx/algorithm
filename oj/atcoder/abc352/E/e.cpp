#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int N = 2e5 + 10;

int n, m;

int p[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void solve() {
    scanf("%d%d", &n, &m);
    iota(p + 1, p + n + 1, 1);
    vector<vector<int>> v(m);
    int sz = n;
    for (int i = 0; i < m; i++) {
        int k, c;
        scanf("%d%d", &k, &c);
        v[i].emplace_back(c);
        while (k--) {
            int x;
            scanf("%d", &x);
            v[i].emplace_back(x);
        }
    }
    sort(v.begin(), v.end(), [](const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    });
    LL res = 0;
    for (auto &group: v) {
        int c = group[0];
        int p1 = find(group[1]);
        for (int i = 2; i < group.size(); i++) {
            int pi = find(group[i]);
            if (p1 != pi) {
                res += c;
                p[pi] = p1;
                sz--;
            }
        }
    }
    if (sz > 1) {
        puts("-1");
    } else {
        printf("%lld\n", res);
    }
}

int main() {
    solve();
    return 0;
}