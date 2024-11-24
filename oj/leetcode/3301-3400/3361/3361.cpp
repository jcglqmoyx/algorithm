#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long shiftDistance(string s, string t, vector<int> &nextCost, vector<int> &previousCost) {
        using LL = long long;
        LL s1[27]{}, s2[28]{};
        for (int i = 1; i <= 26; i++) {
            s1[i] = s1[i - 1] + nextCost[i - 1];
            s2[27 - i] = s2[28 - i] + previousCost[26 - i];
        }
        LL f[26][26];
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (i == j) {
                    f[i][j] = 0;
                } else {
                    if (i < j) {
                        f[i][j] = min(s1[j] - s1[i], s2[1] - s2[i + 2] + s2[j + 2]);
                    } else {
                        f[i][j] = min(s1[26] - s1[i] + s1[j], s2[j + 2] - s2[i + 2]);
                    }
                }
            }
        }
        LL res = 0;
        for (int i = 0; i < s.size(); i++) {
            res += f[s[i] - 'a'][t[i] - 'a'];
        }
        return res;
    }
};