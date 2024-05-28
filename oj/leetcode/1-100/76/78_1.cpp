#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        int ms[123]{}, mt[123]{};
        for (char c: t) {
            mt[c]++;
        }
        int start = -1, end = s.size();
        auto check = [&]() {
            for (int k = 'A'; k <= 'z'; k++) {
                if (ms[k] < mt[k]) return false;
            }
            return true;
        };
        for (int l = 0, r = 0; r < s.size(); r++) {
            ms[s[r]]++;
            while (l <= r && check()) {
                if (r - l + 1 < end - start + 1) {
                    start = l, end = r;
                }
                ms[s[l]]--;
                l++;
            }
        }
        return start == -1 ? "" : s.substr(start, end - start + 1);
    }
};