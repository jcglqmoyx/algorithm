#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string> &words) {
        int res = 0;
        bool st[26]{};
        for (char c: allowed) {
            st[c - 'a'] = true;
        }
        for (auto &s: words) {
            bool flag = true;
            for (char c: s) {
                if (!st[c - 'a']) {
                    flag = false;
                    break;
                }
            }
            res += flag;
        }
        return res;
    }
};