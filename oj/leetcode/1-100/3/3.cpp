#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, cnt[128]{}, chars = 0;
        for (int l = 0, r = 0; r < s.size(); r++) {
            cnt[s[r]]++;
            if (cnt[s[r]] == 1) chars++;
            while (cnt[s[r]] > 1) cnt[s[l]]--, l++;
            res = max(res, r - l + 1);
        }
        return res;
    }
};
