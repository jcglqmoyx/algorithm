#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> res;
        string s;
        for (char c: target) {
            s.push_back('a');
            for (char last = 'a'; last <= c; last++) {
                s.back() = last;
                res.emplace_back(s);
            }
        }
        return res;
    }
};