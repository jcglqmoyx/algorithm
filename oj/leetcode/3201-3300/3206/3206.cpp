#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int> &colors) {
        int res = 0, n = colors.size(), k = 3, cnt = 0;
        for (int l = 0, r = 1; r < n + k - 1; r++) {
            if (colors[r % n] == colors[(r - 1 + n) % n]) {
                cnt++;
            }
            if (r >= k - 1) {
                if (cnt == 0) res++;
                if (colors[l % n] == colors[(l + 1) % n]) {
                    cnt--;
                }
                l++;
            }
        }
        return res;
    }
};