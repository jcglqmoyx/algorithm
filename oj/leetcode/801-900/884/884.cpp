#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream ss1(s1), ss2(s2);
        string w;
        unordered_map<string, int> map1, map2;
        while (ss1 >> w) map1[w]++;
        vector<string> res;
        while (ss2 >> w) {
            map2[w]++;
        }
        for (auto &[k, v]: map1) {
            if (v == 1 && !map2.contains(k)) {
                res.emplace_back(k);
            }
        }
        for (auto &[k, v]: map2) {
            if (v == 1 && !map1.contains(k)) {
                res.emplace_back(k);
            }
        }
        return res;
    }
};