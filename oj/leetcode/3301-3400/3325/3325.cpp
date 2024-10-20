#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        unordered_map<int, int> cnt;
        int res = 0;
        for (int l = 0, r = 0; r < s.size(); r++) {
            cnt[s[r]]++;
            while (cnt[s[r]] >= k) {
                cnt[s[l]]--;
                l++;
            }
            res += l;
        }
        return res;
    }
};