#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getWinner(vector<int> &arr, int k) {
        int n = arr.size(), mx = 0;
        unordered_map<int, int> cnt;
        for (int t = arr[0], i = 1; i < n; i++) {
            if (arr[i] > t) t = arr[i];
            cnt[t]++;
            if (cnt[t] >= k) return t;
            mx = max(mx, t);
        }
        return mx;
    }
};