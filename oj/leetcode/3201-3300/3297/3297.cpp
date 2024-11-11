#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        using ll = long long;
        ll res = 0;
        int c1[26]{}, c2[26]{}, n = word1.size();
        for (char c: word2) c2[c - 'a']++;
        int cnt = 0;
        for (int i: c2) {
            if (i) cnt++;
        }
        for (int valid = 0, l = 0, r = 0; r < n; r++) {
            int u = word1[r] - 'a';
            c1[u]++;
            if (c1[u] == c2[u]) {
                valid++;
                while (valid == cnt) {
                    u = word1[l] - 'a';
                    c1[u]--;
                    if (c1[u] < c2[u]) valid--;
                    l++;
                }
            }
            res += l;
        }
        return res;
    }
};