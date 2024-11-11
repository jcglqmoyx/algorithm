#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        string d[10] = {"", "", "abc", "def", "ghi", "jkl", "mon", "pqrs", "tuv", "wxyz"};
        vector<string> v = {""};
        for (char c: digits) {
            vector<string> t;
            for (const string &s: v) {
                for (char x: d[c - '0']) {
                    t.emplace_back(s + x);
                }
            }
            v = std::move(t);
        }
        return v;
    }
};