#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestAwesome(string s) {
        int res = 0;
        int mp[1024]{};
        memset(mp, -1, sizeof mp);
        mp[0] = 0;
        for (int i = 1, mask = 0; i <= s.size(); i++) {
            mask ^= 1 << (s[i - 1] - '0');
            if (mp[mask] != -1) res = max(res, i - mp[mask]);
            for (int j = 0; j <= 9; j++) {
                int p = mp[mask ^ (1 << j)];
                if (p != -1) {
                    res = max(res, i - p);
                }
            }
            if (mp[mask] == -1) {
                mp[mask] = i;
            }
        }
        return res;
    }
};