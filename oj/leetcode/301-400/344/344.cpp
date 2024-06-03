#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void reverseString(vector<char> &s) {
        for (int l = 0, r = s.size() - 1; l < r; l++, r--) {
            char t = s[l];
            s[l] = s[r];
            s[r] = t;
        }
    }
};