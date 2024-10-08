#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        string stk;
        for (char c: s) {
            if (c == ']' && !stk.empty() && stk.back() == '[') {
                stk.pop_back();
            } else {
                stk.push_back(c);
            }
        }
        return (static_cast<int>(stk.size()) / 2 + 1) / 2;
    }
};