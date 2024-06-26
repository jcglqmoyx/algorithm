#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) return "0";
        string res;
        while (n) {
            int r = n & 1;
            res.push_back(r + '0');
            n = (n - r) / -2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};