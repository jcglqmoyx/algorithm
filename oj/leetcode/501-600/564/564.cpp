#include <bits/stdc++.h>

using namespace std;

class Solution {
    void change(auto &s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            s[j] = s[i];
        }
    }

public:
    string nearestPalindromic(string s) {
        using ll = long long;
        ll num = stoll(s);
        if (num < 10) {
            return to_string(num - 1);
        } else if (num < 100) {
            int dest[] = {9, 11, 22, 33, 44, 55, 66, 77, 88, 99, 101};
            int diff = 1000, res;
            for (int x: dest) {
                int d = abs(num - x);
                if (d && d < diff) {
                    diff = d;
                    res = x;
                }
            }
            return to_string(res);
        }
        int n = s.size();
        change(s);
        vector<ll> v = {stoll(s)};
        if (n & 1) {
            v.emplace_back(num + pow(10, n / 2));
            v.emplace_back(num - pow(10, n / 2));
        } else {
            v.emplace_back(num + pow(10, n / 2));
            v.emplace_back(num - pow(10, n / 2));
            v.emplace_back(num + pow(10, n / 2 - 1));
            v.emplace_back(num - pow(10, n / 2 - 1));
        }
        ll diff = 2e18, res;
        for (ll x: v) {
            string t = to_string(x);
            change(t);
            ll nx = stoll(t), d = abs(num - nx);
            if (d && d <= diff) {
                if (d < diff || d == diff && nx < res) res = nx;
                diff = d;
            }
        }
        return to_string(res);
    }
};