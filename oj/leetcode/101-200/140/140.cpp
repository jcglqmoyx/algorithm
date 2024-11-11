#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        vector<string> res;
        string path;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        function<void(int, int)> dfs = [&](int u, int last) {
            if (u == s.size()) {
                if (!path.empty() && u == last) {
                    res.emplace_back(path);
                }
            } else {
                string t = s.substr(last, u - last + 1);
                if (dict.contains(t)) {
                    auto len = t.size();
                    if (!path.empty()) {
                        len++;
                        path.push_back(' ');
                    }
                    path.append(t);
                    dfs(u + 1, u + 1);
                    path.resize(path.size() - len);
                }
                dfs(u + 1, last);
            }
        };
        dfs(0, 0);
        return res;
    }
};