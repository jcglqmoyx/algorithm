#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> map;
        for (auto &s: strs) {
            auto t = s;
            sort(t.begin(), t.end());
            map[t].emplace_back(s);
        }
        vector<vector<string>> res;
        for (auto &[k, v]: map) {
            res.emplace_back(v);
        }
        return res;
    }
};