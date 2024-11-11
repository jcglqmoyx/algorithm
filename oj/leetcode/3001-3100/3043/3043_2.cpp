#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2) {
        auto n = arr1.size(), m = arr2.size();
        int tot = 1;
        for (int x: arr2) {
            while (x) tot++, x /= 10;
        }
        int tr[tot][10], idx = 0;
        memset(tr, 0, sizeof tr);
        int v[9];
        for (int x: arr2) {
            int cnt = 0;
            while (x) {
                v[cnt++] = x % 10;
                x /= 10;
            }
            int p = 0;
            for (int i = cnt - 1; i >= 0; i--) {
                if (!tr[p][v[i]]) tr[p][v[i]] = ++idx;
                p = tr[p][v[i]];
            }
        }

        int res = 0;
        for (auto x: arr1) {
            int cnt = 0;
            while (x) {
                v[cnt++] = x % 10;
                x /= 10;
            }
            int p = 0;
            for (int i = cnt - 1; i >= 0; i--) {
                if (!tr[p][v[i]]) break;
                p = tr[p][v[i]];
                res = max(res, cnt - i);
            }
        }
        return res;
    }
};