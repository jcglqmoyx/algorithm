#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string makeGood(string s) {
        string res;
        for (char c: s) {
            if (!res.empty() && c != res.back() && toupper(c) == toupper(res.back())) res.pop_back();
            else res.push_back(c);
        }
        return res;
    }
};