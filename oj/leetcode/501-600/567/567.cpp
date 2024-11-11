#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int cnt1[26]{}, cnt2[26]{};
        int diff = 0;
        for (char c: s1) {
            int u = c - 'a';
            cnt1[u]++;
            if (cnt1[u] == 1) diff++;
        }
        auto n = s1.size(), m = s2.size();
        for (int l = 0, r = 0; r < m; r++) {
            int u = s2[r] - 'a';
            cnt2[u]++;
            if (cnt2[u] == cnt1[u]) diff--;
            else if (cnt2[u] - 1 == cnt1[u]) diff++;
            if (!diff) return true;
            if (r + 1 >= n) {
                u = s2[l] - 'a';
                cnt2[u]--;
                if (cnt2[u] == cnt1[u]) diff--;
                else if (cnt2[u] + 1 == cnt1[u]) diff++;
                l++;
            }
        }
        return false;
    }
};