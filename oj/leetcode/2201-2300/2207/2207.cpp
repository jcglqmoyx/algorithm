#include <bits/stdc++.h>

using namespace std;

class Solution {
    long long get(string text, string pattern) {
        long long r = 0;
        for (char c: text) {
            if (c == pattern[1]) r++;
        }
        long long res = r;
        for (char c: text) {
            if (c == pattern[1]) r--;
            if (c == pattern[0]) res += r;
        }
        return res;
    }

public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long res = get(text, pattern);
        reverse(text.begin(), text.end());
        reverse(pattern.begin(), pattern.end());
        return max(res, get(text, pattern));
    }
};