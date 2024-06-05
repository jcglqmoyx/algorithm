#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string> &words) {
        int cnt[26];
        memset(cnt, 0x3f, sizeof cnt);
        for (auto &w: words) {
            int t[26]{};
            for (char c: w) {
                t[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                cnt[i] = min(cnt[i], t[i]);
            }
        }
        vector<string> res;
        for (int i = 0; i < 26; i++) {
            while (cnt[i]--) {
                res.emplace_back(string(1, i + 'a'));
            }
        }
        return res;
    }
};