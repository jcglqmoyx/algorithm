#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int idx = 1;
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            if (word.substr(0, searchWord.size()) == searchWord) {
                return idx;
            }
            idx++;
        }
        return -1;
    }
};