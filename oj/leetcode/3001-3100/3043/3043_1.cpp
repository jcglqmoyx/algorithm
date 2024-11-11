#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2) {
        auto n = arr1.size(), m = arr2.size();
        vector<string> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = to_string(arr1[i]);
        }
        unordered_set < string > s;
        for (int x: arr2) {
            string num = to_string(x);
            for (int i = 1; i <= num.size(); i++) {
                s.emplace(num.substr(0, i));
            }
        }
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.size() > b.size();
        });
        int res = 0;
        for (auto &num: v) {
            if (num.size() < res) break;
            int l = 0, r = num.size();
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (s.contains(num.substr(0, mid))) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            res = max(res, l);
        }
        return res;
    }
};