#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int m = t.size(), j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == t[j]) j++;
        }
        return m - j;
    }
};