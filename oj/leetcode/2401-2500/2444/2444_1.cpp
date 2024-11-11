#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK) {
        long long res = 0;
        multiset<int> sl, sr;
        for (int l = 0, r = 0, i = 0; i < nums.size(); i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                l = i + 1, r = i + 1;
                sl.clear(), sr.clear();
            } else {
                sl.insert(nums[i]), sr.insert(nums[i]);
                if (*sl.begin() == minK && *sl.rbegin() == maxK) {
                    while (*sr.begin() == minK && *sr.rbegin() == maxK) {
                        sr.erase(sr.find(nums[r])), r++;
                    }
                    res += r - l;
                }
            }
        }
        return res;
    }
};