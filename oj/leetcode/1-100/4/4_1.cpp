#include <bits/stdc++.h>

using namespace std;

class Solution {
    int find(vector<int> &nums1, int i, vector<int> &nums2, int j, int k) {
        if (nums1.size() - i > nums2.size() - j) return find(nums2, j, nums1, i, k);
        if (i == nums1.size()) return nums2[j + k - 1];
        if (k == 1) return min(nums1[i], nums2[j]);
        int ni = min(i + k / 2 - 1, (int) nums1.size() - 1), nj = j + (k - k / 2) - 1;
        if (nums1[ni] < nums2[nj]) return find(nums1, ni + 1, nums2, j, k - (ni - i + 1));
        else return find(nums1, i, nums2, nj + 1, k / 2);
    }

public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int tot = nums1.size() + nums2.size();
        if (tot & 1) {
            return find(nums1, 0, nums2, 0, tot / 2 + 1);
        } else {
            return (find(nums1, 0, nums2, 0, tot / 2) + find(nums1, 0, nums2, 0, tot / 2 + 1)) * 0.5;
        }
    }
};