#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getLargestOutlier(vector<int> &nums) {
        int s = 0;
        unordered_map<int, int> cnt;
        for (int x: nums) {
            s += x;
            cnt[x]++;
        }
        int res = INT32_MIN;
        for (auto &[k, v]: cnt) {
            int t = s - k;
            if (!(t & 1)) {
                int special = t / 2;
                if (special == k && v > 1 || special != k && cnt.contains(special)) {
                    res = max(res, k);
                }
            }
        }
        return res;
    }
};