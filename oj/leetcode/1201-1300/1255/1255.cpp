#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score) {
        auto n = words.size();
        int f[1 << n];
        memset(f, 0, sizeof f);
        int cnt[26]{};
        for (char c: letters) cnt[c - 'a']++;
        int s[n];
        memset(s, 0, sizeof s);
        for (int i = 0; i < n; i++) {
            for (char c: words[i]) {
                s[i] += score[c - 'a'];
            }
        }
        for (int i = 0; i < 1 << n; i++) {
            bool ok = true;
            int mp[26]{};
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) {
                    for (char c: words[j]) {
                        mp[c - 'a']++;
                        if (mp[c - 'a'] > cnt[c - 'a']) {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok) break;
                }
            }
            if (ok) {
                for (int j = 0; j < n; j++) {
                    if (i >> j & 1) {
                        f[i] += s[j];
                    }
                }
            }
        }
        return *max_element(f, f + (1 << n));
    }
};