#include <bits/stdc++.h>

using namespace std;

class Solution {
    string helper(string &s, char a, char b) {
        string res;
        int left = 0;
        for (char c: s) {
            if (c == a) {
                res.push_back(c);
                left++;
            } else if (c == b) {
                if (left) {
                    res.push_back(c);
                    left--;
                }
            } else {
                res.push_back(c);
            }
        }
        return res;
    }

public:
    string minRemoveToMakeValid(string s) {
        string res = helper(s, '(', ')');
        reverse(res.begin(), res.end());
        res = helper(res, ')', '(');
        reverse(res.begin(), res.end());
        return res;
    }
};