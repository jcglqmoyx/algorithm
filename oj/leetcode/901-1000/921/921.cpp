#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        string stk;
        for (char c: s) {
            if (c == ')' && !stk.empty() && stk.back() == '(') stk.pop_back();
            else stk.push_back(c);
        }
        return stk.size();
    }
};