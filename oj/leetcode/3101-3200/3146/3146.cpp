#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int p[26], res = 0;
        for (int i = 0; i < s.size(); i++) {
            p[s[i] - 'a'] = i;
        }
        for (int i = 0; i < t.size(); i++) {
            res += abs(i - p[t[i] - 'a']);
        }
        return res;
    }
};