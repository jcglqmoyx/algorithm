#include <bits/stdc++.h>

using namespace std;

int get(char c) {
    if (c == 'a') return 0;
    if (c == 'e') return 1;
    if (c == 'i') return 2;
    if (c == 'o') return 3;
    if (c == 'u') return 4;
    return 5;
}

long long calc(string &s, int k) {
    long long n = s.size(), res = 0;
    unordered_map<int, int> cnt;
    int consonant = 0;
    for (int l = 0, r = 0; r < n; r++) {
        int idx = get(s[r]);
        if (idx < 5) cnt[idx]++;
        else consonant++;
        while (l <= r && consonant >= k && cnt.size() == 5) {
            int u = get(s[l]);
            if (u < 5) {
                if (--cnt[u] == 0) cnt.erase(u);
            } else {
                consonant--;
            }
            l++;
        }
        res += l;
    }
    return res;
}

class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        return calc(word, k) - calc(word, k + 1);
    }
};