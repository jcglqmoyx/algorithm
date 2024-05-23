#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestEqualSubarray(vector<int> &nums, int k) {
        int n = nums.size();
        auto check = [&](int mid) {
            int len = mid + k;
            unordered_map<int, int> cnt;
            for (int l = 0, r = 0; r < n; r++) {
                cnt[nums[r]]++;
                if (cnt[nums[r]] >= mid) return true;
                if (r - l + 1 >= len) {
                    cnt[nums[l]]--;
                    l++;
                }
            }
            return false;
        };
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};