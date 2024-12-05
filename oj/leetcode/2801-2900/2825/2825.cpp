#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0;
        for (; i < str1.size() && j < str2.size();) {
            int y = str2[j] - 'a';
            while (i < str1.size()) {
                int x = str1[i] - 'a';
                if (x == y || (x + 1) % 26 == y) {
                    j++;
                    break;
                }
                i++;
            }
            i++;
        }
        return j == str2.size();
    }
};