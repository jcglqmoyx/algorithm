#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static vector<long long> mostFrequentIDs(vector<int>&nums, vector<int>&freq) {
        const size_t n = nums.size();
        unordered_map<int, long long> cnt;
        multiset<long long> s;
        vector<long long> res(n);
        for (int i = 0; i < n; i++) {
            auto it = s.find(cnt[nums[i]]);
            if (it != s.end()) {
                s.erase(it);
            }
            cnt[nums[i]] += freq[i];
            s.insert(cnt[nums[i]]);
            res[i] = *s.rbegin();
        }
        return res;
    }
};
