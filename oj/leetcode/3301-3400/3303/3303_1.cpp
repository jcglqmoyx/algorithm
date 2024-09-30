#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const LL BASE1 = 31, BASE2 = 37;
const int M1 = 1e9 + 7, M2 = 1e9 + 9;

const int N = 300010;

int p1[N], p2[N];
int hs1[N], hs2[N];
int hp1[N], hp2[N];

int init = []() {
    p1[0] = p2[0] = 1;
    for (int i = 1; i < N; i++) {
        p1[i] = p1[i - 1] * BASE1 % M1;
        p2[i] = p2[i - 1] * BASE2 % M2;
    }
    return 0;
}();

pair<int, int> get_s(int l, int r) {
    int a = ((hs1[r] - (LL) hs1[l - 1] * p1[r - l + 1]) % M1 + M1) % M1;
    int b = ((hs2[r] - (LL) hs2[l - 1] * p2[r - l + 1]) % M2 + M2) % M2;
    return {a, b};
}

pair<int, int> get_p(int l, int r) {
    int a = ((hp1[r] - (LL) hp1[l - 1] * p1[r - l + 1]) % M1 + M1) % M1;
    int b = ((hp2[r] - (LL) hp2[l - 1] * p2[r - l + 1]) % M2 + M2) % M2;
    return {a, b};
}

class Solution {
public:
    int minStartingIndex(string s, string pattern) {
        auto n = s.size(), m = pattern.size();
        if (m == 1) return 0;
        hs1[0] = hs2[0] = 0;
        for (int i = 1; i <= n; i++) {
            hs1[i] = (hs1[i - 1] * BASE1 + s[i - 1] - 'a') % M1;
            hs2[i] = (hs2[i - 1] * BASE2 + s[i - 1] - 'a') % M2;
        }
        hp1[0] = hp2[0] = 0;
        for (int i = 1; i <= m; i++) {
            hp1[i] = (hp1[i - 1] * BASE1 + pattern[i - 1] - 'a') % M1;
            hp2[i] = (hp2[i - 1] * BASE2 + pattern[i - 1] - 'a') % M2;
        }
        for (int i = 1; i + m - 1 <= n; i++) {
            int l = i - 1, r = i + m - 1;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (get_s(i, mid) == get_p(1, mid - i + 1)) l = mid;
                else r = mid - 1;
            }
            if (l >= i + m - 2) return i - 1;
            if (l == i - 1) {
                if (get_s(i + 1, i + m - 1) == get_p(2, m)) return i - 1;
            } else if (get_s(l + 2, i + m - 1) == get_p(l + 2 - i + 1, m)) {
                return i - 1;
            }
        }
        return -1;
    }
};