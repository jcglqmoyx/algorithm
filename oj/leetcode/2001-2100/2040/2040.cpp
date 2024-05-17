#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, long long k) {
        using LL = long long;
        vector<int> ln, lp, rn, rp;
        for (int x: nums1) {
            if (x < 0) ln.emplace_back(x);
            else lp.emplace_back(x);
        }
        for (int x: nums2) {
            if (x < 0) rn.emplace_back(x);
            else rp.emplace_back(x);
        }
        int a = ln.size(), b = lp.size(), c = rn.size(), d = rp.size();
        auto check = [&](auto mid) {
            LL cnt = 0;

            for (int i = a - 1, j = 0; i >= 0 && j < c; i--) {
                while (j < c && ln[i] * 1LL * rn[j] > mid) j++;
                cnt += c - j;
            }
            if (cnt >= k) return true;

            for (int i = b - 1, j = c - 1; i >= 0 && j >= 0; i--) {
                while (j >= 0 && lp[i] * 1LL * rn[j] > mid) j--;
                cnt += j + 1;
            }
            if (cnt >= k) return true;

            for (int i = 0, j = 0; i < a && j < d; i++) {
                while (j < d && ln[i] * 1LL * rp[j] > mid) j++;
                cnt += d - j;
            }
            if (cnt >= k) return true;

            for (int i = 0, j = d - 1; i < b && j >= 0; i++) {
                while (j >= 0 && lp[i] * 1LL * rp[j] > mid) j--;
                cnt += j + 1;
            }
            return cnt >= k;
        };

        LL x = nums1[0] * 1LL * nums2[0];
        LL y = nums1[0] * 1LL * nums2.back();
        LL z = nums1.back() * 1LL * nums2[0];
        LL w = nums1.back() * 1LL * nums2.back();
        LL l = min(min(x, y), min(z, w)), r = max(max(x, y), max(z, w));

        while (l < r) {
            LL mid = (l + r) >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};