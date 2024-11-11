#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        auto n = s.size();
        int ne[n];
        ne[0] = -1;
        for (int i = 1, j = -1; i < n; i++) {
            while (~j && s[i] != s[j + 1]) j = ne[j];
            if (s[i] == s[j + 1]) j++;
            ne[i] = j;
        }
        for (int i = 0, j = -1; i < n * 2 - 1; i++) {
            while (~j && goal[i % n] != s[j + 1]) j = ne[j];
            if (goal[i % n] == s[j + 1]) j++;
            if (j == n - 1) return true;
        }
        return false;
    }
};