#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int cnt[2]{}, res = 0;
        for (int l = 0, r = 0; r < s.size(); r++) {
            cnt[s[r] - '0']++;
            while (cnt[0] > k && cnt[1] > k) {
                cnt[s[l] - '0']--;
                l++;
            }
            res += r - l + 1;
        }
        return res;
    }
};