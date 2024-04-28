#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int medianOfUniquenessArray(vector<int> &nums) {
        auto n = nums.size();
        auto tot = n * (n + 1) / 2;
        auto valid = [&](auto mid) {
            long long cnt = 0;
            unordered_map<int, int> mp;
            for (int l = 0, r = 0; r < n; r++) {
                mp[nums[r]]++;
                while (mp.size() > mid) {
                    mp[nums[l]]--;
                    if (mp[nums[l]] == 0) {
                        mp.erase(nums[l]);
                    }
                    l++;
                }
                cnt += r - l + 1;
            }
            return cnt >= (tot + 1) / 2;
        };
        size_t l = 1, r = n;
        while (l < r) {
            auto mid = (l + r) >> 1;
            if (valid(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};