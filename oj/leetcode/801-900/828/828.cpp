#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniqueLetterString(string s) {
        vector<vector<int>> map(26);
        long long n = s.size();
        for (int i = 0; i < n; i++) {
            map[s[i] - 'A'].emplace_back(i);
        }
        long long res = 0;
        for (int u = 0; u < 26; u++) {
            for (int i = 0; i < map[u].size(); i++) {
                long long l = i ? map[u][i - 1] + 1 : 0;
                long long r = i + 1 < map[u].size() ? map[u][i + 1] - 1 : n - 1;
                res += (map[u][i] - l + 1) * (r - map[u][i] + 1);
            }
        }
        return res;
    }
};