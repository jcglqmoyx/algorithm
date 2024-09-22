#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool reportSpam(vector<string> &message, vector<string> &bannedWords) {
        unordered_set < string > S(bannedWords.begin(), bannedWords.end());
        int cnt = 0;
        for (auto &s: message) {
            if (S.contains(s)) {
                cnt++;
                if (cnt >= 2) return true;
            }
        }
        return false;
    }
};