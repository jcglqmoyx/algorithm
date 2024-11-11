#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string findLatestTime(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '?') {
                if (i == 0) {
                    s[i] = s[i + 1] <= '1' || s[i + 1] == '?' ? '1' : '0';
                } else if (i == 1) {
                    s[i] = s[i - 1] == '0' ? '9' : '1';
                } else if (i == 3) {
                    s[i] = '5';
                } else if (i == 4) {
                    s[i] = '9';
                }
            }
        }
        return s;
    }
};