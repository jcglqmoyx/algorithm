#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        for (int absent = 0, i = 0; i < s.size(); i++) {
            if (s[i] == 'A') {
                absent++;
                if (absent == 2) {
                    return false;
                }
            } else if (s[i] == 'L') {
                if (i + 2 < s.size() && s[i + 1] == s[i] && s[i + 2] == s[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};