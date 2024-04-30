#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long res = 0;
        int cnt[1024]{};
        cnt[0] = 1;
        int mask = 0;
        for (char c: word) {
            mask ^= 1 << (c - 'a');
            res += cnt[mask];
            for (int i = 0; i < 10; i++) {
                res += cnt[mask ^ (1 << i)];
            }
            cnt[mask]++;
        }
        return res;
    }
};
