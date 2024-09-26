#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(string s) {
        int n = s.size(), res = 0;
        for (int i = 0; i < 1 << n; i++) {
            for (int j = i; j; j = (j - 1) & i) {
                char s1[n], s2[n];
                int n1 = 0, n2 = 0;
                for (int k = 0; k < n; k++) {
                    if (j >> k & 1) {
                        s2[n2++] = s[k];
                    } else if (i >> k & 1) {
                        s1[n1++] = s[k];
                    }
                }
                bool valid = true;
                for (int l = 0, r = n1 - 1; l < r; l++, r--) {
                    if (s1[l] != s1[r]) {
                        valid = false;
                        break;
                    }
                }
                if (!valid) continue;
                for (int l = 0, r = n2 - 1; l < r; l++, r--) {
                    if (s2[l] != s2[r]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) res = max(res, n1 * n2);
            }
        }
        return res;
    }
};