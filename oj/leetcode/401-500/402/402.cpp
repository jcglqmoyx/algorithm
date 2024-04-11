#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string s;
        for (int i = 0; i < num.size(); i++) {
            while (k && !s.empty() && s.back() > num[i]) s.pop_back(), k--;
            s.push_back(num[i]);
        }
        while (k--) s.pop_back();
        reverse(s.begin(), s.end());
        while (s.size() > 1 && s.back() == '0') s.pop_back();
        reverse(s.begin(), s.end());
        return s.empty() ? "0" : s;
    }
};