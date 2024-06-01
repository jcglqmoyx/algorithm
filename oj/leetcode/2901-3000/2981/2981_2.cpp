#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        struct T {
            int a = -1, b = -1, c = -1;
        };
        vector<T> g(26);
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            int j = i + 1;
            while (j < s.size() && s[j] == s[i]) j++;
            int len = j - i;
            auto &t = g[s[i] - 'a'];
            if (len > t.a) {
                t.c = t.b, t.b = t.a, t.a = len;
            } else if (len > t.b) {
                t.c = t.b, t.b = len;
            } else if (len > t.c) {
                t.c = len;
            }
            res = max({res, t.a - 2, min(t.a - 1, t.b), t.c});
            i = j - 1;
        }
        return res ? res : -1;
    }
};