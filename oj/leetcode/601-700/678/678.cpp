#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int mn = 0, mx = 0;
        for (char c: s) {
            if (c == '(') {
                mn++, mx++;
            } else if (c == ')') {
                mn = max(mn - 1, 0), mx--;
            } else {
                mn = max(mn - 1, 0), mx++;
            }
            if (mx < 0) return false;
        }
        return mn == 0;
    }
};