#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumAddedInteger(vector<int> &nums1, vector<int> &nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for (int i = 2; i >= 0; i--) {
            int j = 0;
            for (int u = i; u < nums1.size() && j < nums2.size(); u++) {
                while (u < nums1.size() && nums1[u] - nums2[j] != nums1[i] - nums2[0]) u++;
                if (u < nums1.size()) j++;
            }
            if (j == nums2.size()) {
                return nums2[0] - nums1[i];
            }
        }
        return 0;
    }
};