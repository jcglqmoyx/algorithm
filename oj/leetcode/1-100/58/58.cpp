#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                int j = i - 1;
                while (j >= 0 && s[j] != ' ') j--;
                return i - j;
            }
        }
        return 0;
    }
};