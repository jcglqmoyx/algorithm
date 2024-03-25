#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int cnt[123]{}, res = 0;
        for (int l = 0, r = 0; r < s.size(); r++) {
            cnt[s[r]]++;
            while (cnt[s[r]] > 2) cnt[s[l]]--, l++;
            res = max(res, r - l + 1);
        }
        return res;
    }
};
