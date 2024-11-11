#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int cnt_s[123]{}, cnt_t[123]{};
        for (char c: t) {
            cnt_t[c]++;
        }
        int less = 0;
        for (int c = 'A'; c <= 'z'; c++) {
            less += cnt_s[c] < cnt_t[c];
        }
        int start = -1, end = s.size();
        for (int l = 0, r = 0; r < s.size(); r++) {
            cnt_s[s[r]]++;
            less -= cnt_s[s[r]] == cnt_t[s[r]];
            while (less == 0) {
                if (r - l + 1 < end - start + 1) {
                    start = l, end = r;
                }
                cnt_s[s[l]]--;
                if (cnt_s[s[l]] + 1 == cnt_t[s[l]]) less++;
                l++;
            }
        }
        return start == -1 ? "" : s.substr(start, end - start + 1);
    }
};
