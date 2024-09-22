#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>> &trust) {
        int in[n + 1], out[n + 1];
        memset(in, 0, sizeof in);
        memset(out, 0, sizeof out);
        for (auto &t: trust) {
            in[t[0]]++;
            out[t[1]]++;
        }
        for (int i = 1; i <= n; i++) {
            if (in[i] == 0 && out[i] == n - 1) return i;
        }
        return -1;
    }
};