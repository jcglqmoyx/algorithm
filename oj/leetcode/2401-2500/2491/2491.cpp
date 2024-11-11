#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int> &skill) {
        unordered_map<int, int> cnt;
        int n = skill.size(), s = 0, mx = 0;
        for (int x: skill) {
            cnt[x]++;
            s += x;
            mx = max(mx, x);
        }
        if (2 * s % n) return -1;
        int sub = s / (n / 2);
        long long res = 0;
        for (int i = 1; i <= mx; i++) {
            if (!cnt.contains(i)) continue;
            if (i * 2 == sub) {
                if (cnt[i] & 1) return -1;
                else res += i * i * 1LL * cnt[i] / 2;
            } else {
                if (cnt[i] != cnt[sub - i]) return -1;
                cnt.erase(sub - i);
                res += i * (sub - i) * 1LL * cnt[i];
            }
        }
        return res;
    }
};