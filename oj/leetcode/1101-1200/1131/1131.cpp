#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxAbsValExpr(vector<int> &arr1, vector<int> &arr2) {
        auto n = arr1.size();
        int a1 = 1e9, a2 = 0;
        int b1 = 1e9, b2 = 0;
        int c1 = 1e9, c2 = 0;
        int d1 = 1e9, d2 = 0;
        for (int i = 0; i < n; i++) {
            int a = arr1[i] - arr2[i] + i;
            a1 = min(a1, a), a2 = max(a2, a);
            int b = -arr1[i] - arr2[i] + i;
            b1 = min(b1, b), b2 = max(b2, b);
            int c = -arr1[i] + arr2[i] + i;
            c1 = min(c1, c), c2 = max(c2, c);
            int d = arr1[i] + arr2[i] + i;
            d1 = min(d1, d), d2 = max(d2, d);
        }
        return max(max(a2 - a1, b2 - b1), max(c2 - c1, d2 - d1));
    }
};