#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximizeWin(vector<int> &prizePositions, int k) {
        int n = prizePositions.size(), res = 0;
        int l[n + 1];
        l[0] = 0;
        for (int i = 1, j = 1; j <= n; j++) {
            while (prizePositions[j - 1] - prizePositions[i - 1] > k) i++;
            l[j] = j - i + 1;
            l[j] = max(l[j], l[j - 1]);
        }
        for (int r = 0, i = n, j = n; i >= 1; i--) {
            while (prizePositions[j - 1] - prizePositions[i - 1] > k) j--;
            int ri = j - i + 1;
            ri = max(ri, r);
            res = max(res, l[i - 1] + ri);
            r = ri;
        }
        return res;
    }
};