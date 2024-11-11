#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using ULL = unsigned long long;

const int N = 5e5 + 10;
const ULL P1 = 131;
const ULL P2 = 137;
const ULL MOD = 1e9 + 7;

ULL h1[N], h2[N];
ULL p1[N], p2[N];

int init = []() {
    p1[0] = p2[0] = 1;
    for (int i = 1; i < N; i++) {
        p1[i] = p1[i - 1] * P1 % MOD;
        p2[i] = p2[i - 1] * P2;
    }
    return 0;
}();

pair<ULL, ULL> get(int l, int r) {
    ULL hash1 = (h1[r] - h1[l - 1] * p1[r - l + 1] % MOD + MOD) % MOD;
    ULL hash2 = h2[r] - h2[l - 1] * p2[r - l + 1];
    return {hash1, hash2};
}

class Solution {
public:
    long long countPrefixSuffixPairs(vector<string> &words) {
        unordered_map<ULL, LL> cnt;
        LL res = 0;
        for (auto &s: words) {
            int n = s.size();
            h1[0] = h2[0] = 0;
            for (int i = 1; i <= n; i++) {
                h1[i] = (h1[i - 1] * P1 + s[i - 1]) % MOD;
                h2[i] = h2[i - 1] * P2 + s[i - 1];
            }
            for (int l = 1; l <= n; l++) {
                auto prefix = get(1, l);
                auto suffix = get(n - l + 1, n);
                if (prefix == suffix) {
                    res += cnt[prefix.first];
                }
            }
            auto hash = get(1, n);
            cnt[hash.first]++;
        }
        return res;
    }
};