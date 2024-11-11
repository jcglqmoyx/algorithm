#include <bits/stdc++.h>

using namespace std;

const int N = 1500005;

int tr[N][26];
bool is_end[N];

class Solution {
public:
    bool reportSpam(vector<string> &message, vector<string> &bannedWords) {
        int idx = 0;
        int tot = 1;
        for (auto &s: bannedWords) tot += s.size();
        memset(tr, 0, sizeof(tr[0]) * tot);
        memset(is_end, 0, sizeof(bool) * tot);

        auto insert = [&](string &s) {
            int p = 0;
            for (auto c: s) {
                int u = c - 'a';
                if (!tr[p][u]) tr[p][u] = ++idx;
                p = tr[p][u];
            }
            is_end[p] = true;
        };

        auto exists = [&](string &s) {
            int p = 0;
            for (auto c: s) {
                int u = c - 'a';
                if (!tr[p][u]) return false;
                p = tr[p][u];
            }
            return is_end[p];
        };

        for (auto &s: bannedWords) insert(s);
        int cnt_banned_words = 0;
        for (auto &s: message) {
            if (exists(s)) {
                if (++cnt_banned_words >= 2) return true;
            }
        }
        return false;
    }
};