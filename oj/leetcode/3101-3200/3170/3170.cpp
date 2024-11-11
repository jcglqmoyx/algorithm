#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string clearStars(string s) {
        vector<int> g[26];
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                for (auto &v: g) {
                    if (!v.empty()) {
                        v.pop_back();
                        break;
                    }
                }
            } else {
                g[s[i] - 'a'].emplace_back(i);
            }
        }
        vector<pair<int, int>> v;
        for (int i = 0; i < 26; i++) {
            for (auto x: g[i]) {
                v.emplace_back(x, i);
            }
        }
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.first < b.first;
        });
        string res(v.size(), 0);
        for (int i = 0; i < v.size(); i++) {
            res[i] = v[i].second + 'a';
        }
        return res;
    }
};