#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        if (n < k * 3) return -1;
        if (!k) return 0;
        int cnt[26]{};
        int r = n - 1, res = -1;
        for (; r >= 0; r--) {
            cnt[s[r] - 'a']++;
            if (cnt[0] >= k && cnt[1] >= k && cnt[2] >= k) {
                res = n - r;
                break;
            }
        }
        if (res == -1) return -1;
        for (int l = 0; l < n; l++) {
            cnt[s[l] - 'a']++;
            while (r < n) {
                if (s[r] > 'c') r++;
                else if (cnt[s[r] - 'a'] > k) {
                    cnt[s[r] - 'a']--;
                    r++;
                } else {
                    break;
                }
            }
            res = min(res, l + 1 + n - r);
        }
        return res;
    }
};