#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string compressedString(string word) {
        string comp;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            while (j <= min(i + 8, n) && word[j] == word[i]) j++;
            comp.push_back(j - i + '0');
            comp.push_back(word[i]);
            i = j - 1;
        }
        return comp;
    }
};