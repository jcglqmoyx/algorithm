#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minLength(string s) {
        string res;
        for (char c: s) {
            if (!res.empty() && (res.back() == 'C' && c == 'D' || res.back() == 'A' && c == 'B')) res.pop_back();
            else res.push_back(c);
        }
        return res.size();
    }
};