#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int len = 1, res = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1] + 1) len++;
            else res = max(res, len), len = 1;
        }
        res = max(res, len);
        return res;
    }
};