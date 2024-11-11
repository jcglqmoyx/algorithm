#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPairs(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        unordered_map<int, int> cnt;
        for (int x: nums) {
            unordered_set<int> st = {x};
            string s = to_string(x);
            auto n = s.size();
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    swap(s[i], s[j]);
                    st.emplace(stoi(s));
                    for (int p = i + 1; p < n; p++) {
                        for (int q = p + 1; q < n; q++) {
                            swap(s[p], s[q]);
                            st.emplace(stoi(s));
                            swap(s[p], s[q]);
                        }
                    }
                    swap(s[i], s[j]);
                }
            }
            for (int num: st) {
                ans += cnt[num];
            }
            cnt[x]++;
        }
        return ans;
    }
};