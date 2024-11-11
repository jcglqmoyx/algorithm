#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minExtraChar(string s, vector<string> &dictionary) {
        unordered_set < string > set(dictionary.begin(), dictionary.end());
        auto n = s.size();
        int f[n + 1];
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            f[i] = f[i - 1] + 1;
            for (int j = 1; j <= i; j++) {
                if (set.contains(s.substr(j - 1, i - j + 1))) {
                    f[i] = min(f[i], f[j - 1]);
                    break;
                }
            }
        }
        return f[n];
    }
};