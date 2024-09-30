#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        using ll = long long;
        auto get = [](char c) {
            if (c == 'a') return 0;
            if (c == 'e') return 1;
            if (c == 'i') return 2;
            if (c == 'o') return 3;
            if (c == 'u') return 4;
            return 5;
        };
        int n = word.size();
        int s[n + 1][6];
        memset(s[0], 0, sizeof s[0]);
        ll res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 6; j++) {
                s[i][j] = s[i - 1][j];
            }
            s[i][get(word[i - 1])]++;
        }
        for (int i = 5 + k; i <= n; i++) {
            int l = 0, r = i;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (s[i][5] - s[mid - 1][5] < k) r = mid - 1;
                else l = mid;
            }
            if (l == 0) continue;
            int right_k = l;

            l = 1, r = right_k;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (s[i][5] - s[mid - 1][5] > k) l = mid + 1;
                else r = mid;
            }
            if (s[i][5] - s[l - 1][5] != k) continue;

            int left_k = l;

            l = 0, r = i - 4;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                bool ok = true;
                for (int j = 0; j < 5; j++) {
                    if (s[i][j] - s[mid - 1][j] == 0) {
                        ok = false;
                        break;
                    }
                }
                if (ok) l = mid;
                else r = mid - 1;
            }

            if (l == 0) continue;

            int right_vowel = l;
            int left_vowel = 1;

            if (left_k >= left_vowel && left_k <= right_vowel) {
                res += min(right_vowel, right_k) - left_k + 1;
            } else if (left_vowel >= left_k && left_vowel <= right_k) {
                res += min(right_vowel, right_k) - left_vowel + 1;
            }
        }
        return res;
    }
};