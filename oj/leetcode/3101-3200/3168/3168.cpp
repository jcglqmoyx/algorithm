#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumChairs(string s) {
        int res = 0, t = 0;
        for (char c: s) {
            if (c == 'E') {
                t++;
                res = max(res, t);
            } else {
                t--;
            }
        }
        return res;
    }
};