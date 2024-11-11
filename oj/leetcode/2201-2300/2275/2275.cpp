#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestCombination(vector<int> &candidates) {
        int res = 0;
        int m = log2(*max_element(candidates.begin(), candidates.end()));
        for (int i = 0; i <= m; i++) {
            int cnt = 0;
            for (int x: candidates) {
                if (x >> i & 1) {
                    cnt++;
                }
            }
            res = max(res, cnt);
        }
        return res;
    }
};