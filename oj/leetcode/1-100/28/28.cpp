#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        auto m = haystack.size(), n = needle.size();
        int ne[n];
        ne[0] = -1;
        for (int i = 1, j = -1; i < n; i++) {
            while (j != -1 && needle[j + 1] != needle[i]) j = ne[j];
            if (needle[j + 1] == needle[i]) j++;
            int t = j;
            if (t != -1 && needle[i + 1] == needle[t + 1]) t = ne[t];
            ne[i] = t;
        }
        for (int i = 0, j = -1; i < m; i++) {
            while (j != -1 && needle[j + 1] != haystack[i]) j = ne[j];
            if (needle[j + 1] == haystack[i]) j++;
            if (j == n - 1) return i - n + 1;
        }
        return -1;
    }
};