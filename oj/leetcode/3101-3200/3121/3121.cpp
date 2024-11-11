#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string s) {
        int l[123]{}, r[123]{}, st[123]{};
        for (char c: s) {
            r[c]++;
        }
        int res = 0;
        for (char c: s) {
            r[c]--;
            if (c >= 'A' && c <= 'Z') {
                if (st[c]) continue;
                if (l[tolower(c)] && !r[tolower(c)]) res++;
                st[c]++;
            }
            l[c]++;
        }
        return res;
    }
};