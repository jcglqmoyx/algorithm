#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        auto n = s.size();
        int ne[n];
        ne[0] = -1;
        for (int i = 1, j = -1; i < n; i++) {
            while (j != -1 && s[j + 1] != s[i]) j = ne[j];
            if (s[j + 1] == s[i]) j++;
            ne[i] = j;
        }
        return s.substr(0, ne[n - 1] + 1);
    }
};