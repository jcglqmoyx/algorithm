#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string smallestString(string s) {
        bool changed = false;
        for (char &c: s) {
            if (c != 'a') {
                c--;
                changed = true;
            } else {
                if (changed) {
                    break;
                }
            }
        }
        if (!changed) {
            char c = s.back();
            s.back() = (c - 'a' - 1 + 26) % 26 + 'a';
        }
        return s;
    }
};