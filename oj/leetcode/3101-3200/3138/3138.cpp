#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();
        for (int k = 1; k * 2 <= n; k++) {
            if (n % k) continue;
            vector<int> cnt(26);
            for (int j = 0; j < k; j++) cnt[s[j] - 'a']++;
            bool flag = true;
            for (int i = k; i < n; i += k) {
                vector<int> t(26);
                for (int j = i; j < i + k; j++) {
                    t[s[j] - 'a']++;
                }
                if (cnt != t) {
                    flag = false;
                    break;
                }
            }
            if (flag) return k;
        }
        return n;
    }
};