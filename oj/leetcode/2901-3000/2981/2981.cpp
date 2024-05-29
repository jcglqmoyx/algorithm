#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        vector<priority_queue<int, vector<int>, greater<>>> v(26);
        int res = -1;
        for (int i = 0; i < s.size(); i++) {
            int j = i + 1;
            while (j < s.size() && s[j] == s[i]) j++;
            int len = j - i;
            if (len >= 3) res = max(res, len - 2);
            int u = s[i] - 'a';
            v[u].emplace(len);
            if (v[u].size() >= 3) {
                if (v[u].size() > 3) {
                    v[u].pop();
                }
                res = max(res, v[u].top());
            }
        }
        return res;
    }
};