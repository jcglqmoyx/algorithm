#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int> &spaces) {
        string res;
        for (int i = 0, j = 0; i < s.size(); i++) {
            if (j < spaces.size() && spaces[j] == i) {
                res.push_back(' ');
                j++;
            }
            res.push_back(s[i]);
        }
        return res;
    }
};