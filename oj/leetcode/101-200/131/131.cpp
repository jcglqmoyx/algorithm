#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;

        auto is_palindrome = [&](int l, int r) {
            while (l < r) {
                if (s[l] != s[r]) return false;
                l++;
                r--;
            }
            return true;
        };
        function<void(int, int)> dfs = [&](int u, int last) {
            if (u == s.size()) {
                if (is_palindrome(last, u)) {
                    res.emplace_back(path);
                }
            } else {
                dfs(u + 1, last);
                if (is_palindrome(last, u)) {
                    path.emplace_back(s.substr(last, u - last + 1));
                    dfs(u + 1, u + 1);
                    path.pop_back();
                }
            }
        };
        dfs(0, 0);
        return res;
    }
};