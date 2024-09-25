#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long distinctNames(vector<string> &ideas) {
        unordered_set<string> set(ideas.begin(), ideas.end());
        int cnt[26][26]{};
        for (auto &s: ideas) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == s[0]) continue;
                string t = c + s.substr(1);
                if (!set.contains(t)) cnt[s[0] - 'a'][c - 'a']++;
            }
        }
        long long res = 0;
        for (auto &s: ideas) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == s[0]) continue;
                auto t = c + s.substr(1);
                if (set.contains(t)) continue;
                res += cnt[c - 'a'][s[0] - 'a'];
            }
        }
        return res;
    }
};