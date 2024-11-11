#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int> &nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<>());
        auto check = [&](int mid) {
            int cnt = 0;
            for (int i = 0, j = 1; j < n; j++) {
                while (i < j && nums[i] - nums[j] > mid) i++;
                cnt += j - i;
            }
            return cnt >= k;
        };
        int l = 0, r = nums.front() - nums.back();
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};