#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> map;
        for (auto &s: strs) {
            int cnt[26]{};
            for (char c: s) cnt[c - 'a']++;
            string key;
            for (int i = 0; i < 26; i++) key += to_string(cnt[i]) + ' ';
            map[key].emplace_back(s);
        }
        vector<vector<string>> res;
        for (auto &[k, v]: map) {
            res.emplace_back(v);
        }
        return res;
    }
};