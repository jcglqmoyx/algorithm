#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt_upper = 0;
        for (int i = 0; i < word.size(); i++) {
            if (i + 1 < word.size() && islower(word[i]) && isupper(word[i + 1]) || i && i + 1 < word.size() && isupper(word[i - 1]) && isupper(word[i]) && islower(word[i + 1])) {
                return false;
            }
        }
        return true;
    }
};