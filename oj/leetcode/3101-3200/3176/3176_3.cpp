#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int> &nums, int k) {
        unordered_map<int, vector<int>> f;
        vector<int> mx(k + 1);
        for (int x: nums) {
            if (!f.contains(x)) f[x] = vector<int>(k + 1);
            for (int i = k; i >= 0; i--) {
                f[x][i]++;
                if (i) {
                    f[x][i] = max(f[x][i], mx[i - 1] + 1);
                }
                mx[i] = max(mx[i], f[x][i]);
            }
        }
        return mx[k];
    }
};