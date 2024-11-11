#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char st[128]{}, ts[128]{};
        for (int i = 0; i < s.size(); i++) {
            char cs = s[i], ct = t[i];
            if (st[cs] && st[cs] != ct || ts[ct] && ts[ct] != cs) return false;
            st[cs] = ct, ts[ct] = cs;
        }
        return true;
    }
};