#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        t = ' ' + s + '#' + t;
        auto n = t.size();
        int ne[n];
        ne[1] = 0;
        for (int i = 2, j = 0; i < n; i++) {
            while (j && t[i] != t[j + 1]) j = ne[j];
            if (t[i] == t[j + 1]) j++;
            ne[i] = j;
        }
        int len = ne[n - 1];
        t = s.substr(len);
        reverse(t.begin(), t.end());
        return t + s;
    }
};