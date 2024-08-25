#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPairs(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        unordered_map<int, int> cnt;
        for (int x: nums) {
            res += cnt[x];
            auto s = to_string(x);
            auto n = s.size();
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (s[i] == s[j]) continue;
                    swap(s[i], s[j]);
                    res += cnt[stoi(s)];
                    swap(s[i], s[j]);
                }
            }
            cnt[x]++;
        }
        return res;
    }
};