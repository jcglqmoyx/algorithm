#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        int cnt1[1001]{}, cnt2[1001]{};
        for (int x: nums1) cnt1[x]++;
        for (int x: nums2) cnt2[x]++;
        vector<int> res;
        for (int i = 0; i <= 1000; i++) {
            int t = min(cnt1[i], cnt2[i]);
            while (t--) {
                res.emplace_back(i);
            }
        }
        return res;
    }
};