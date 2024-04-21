#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        bool st[123]{};
        for (char c: word) st[c] = true;
        int res = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            res += st[c] && st[toupper(c)];
        }
        return res;
    }
};