#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        unordered_map<int, int> cnt1;
        for (int x: nums1) {
            if (x % k == 0) {
                cnt1[x / k]++;
            }
        }
        if (cnt1.empty()) return 0;
        unordered_map<int, int> cnt2;
        for (int x: nums2) {
            cnt2[x]++;
        }
        int mx = ranges::max_element(cnt1)->first;
        int res = 0;
        for (auto &[x, cnt]: cnt2) {
            int s = 0;
            for (int a = x; a <= mx; a += x) {
                s += cnt1[a];
            }
            res += s * cnt;
        }
        return res;
    }
};