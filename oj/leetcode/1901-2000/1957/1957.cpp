#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        string res;
        for (char c: s) {
            if (res.size() < 2 || res[res.size() - 2] != res.back() || res.back() != c) {
                res.push_back(c);
            }
        }
        return res;
    }
};