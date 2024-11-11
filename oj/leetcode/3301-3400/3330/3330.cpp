#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        int res = 1;
        for (int i = 0; i < word.size(); i++) {
            int j = i + 1;
            while (j < word.size() && word[j] == word[i]) j++;
            res += j - i - 1;
            i = j - 1;
        }
        return res;
    }
};