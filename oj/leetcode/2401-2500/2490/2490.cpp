#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isCircularSentence(string sentence) {
        if (sentence[0] != sentence.back()) {
            return false;
        }
        for (int i = 0; i + 1 < sentence.size(); i++) {
            if (sentence[i] == ' ') {
                if (sentence[i - 1] != sentence[i + 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};