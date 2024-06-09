#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCapability(vector<int> &nums, int k) {
        int l = 1e9, r = 0;
        for (int x: nums) {
            l = min(l, x);
            r = max(r, x);
        }
        auto check = [&](int mid) {
            int cnt = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= mid) {
                    cnt++;
                    i++;
                }
            }
            return cnt >= k;
        };
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};