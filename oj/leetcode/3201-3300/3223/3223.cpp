#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int cnt[26]{};
        for (char c: s) {
            cnt[c - 'a']++;
        }
        int res = 0;
        for (int i = 0; i < 26; i++) {
            cnt[i] ? res += cnt[i] & 1 ? 1 : 2 : 0;
        }
        return res;
    }
};