#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<long long> findXSum(vector<int> &nums, int k, int x) {
        unordered_map<int, int> cnt;
        set<pair<int, int>> s1, s2;
        long long sum = 0;
        auto l2r = [&]() {
            if (s1.empty()) return;
            sum += s1.rbegin()->first * 1LL * s1.rbegin()->second;
            s2.emplace(*s1.rbegin());
            s1.erase(s1.find(*s1.rbegin()));
        };
        auto r2l = [&]() {
            if (s2.empty()) return;
            sum -= s2.begin()->first * 1LL * s2.begin()->second;
            s1.emplace(*s2.begin());
            s2.erase(s2.begin());
        };
        vector<long long> res;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            cnt[nums[r]]++;
            pair<int, int> old_pair = {cnt[nums[r]] - 1, nums[r]};
            pair<int, int> new_pair = {cnt[nums[r]], nums[r]};
            if (s1.contains(old_pair)) {
                s1.erase(old_pair);
                s1.emplace(new_pair);
            } else {
                s2.erase(old_pair);
                s2.emplace(new_pair);
                sum += nums[r];
            }
            l2r();
            r2l();
            while (s2.size() > x) {
                r2l();
            }
            while (!s1.empty() && s2.size() < x) {
                l2r();
                r2l();
                l2r();
            }
            if (r >= k - 1) {
                res.emplace_back(sum);
                cnt[nums[l]]--;
                old_pair = {cnt[nums[l]] + 1, nums[l]};
                new_pair = {cnt[nums[l]], nums[l]};
                if (s1.contains(old_pair)) {
                    s1.erase(old_pair);
                    s1.emplace(new_pair);
                } else {
                    s2.erase(old_pair);
                    s2.emplace(new_pair);
                    sum -= nums[l];
                }
                l++;
            }
        }
        return res;
    }
};