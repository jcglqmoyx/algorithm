#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canArrange(vector<int> &arr, int k) {
        auto n = arr.size();
        int cnt[k];
        memset(cnt, 0, sizeof cnt);
        for (int x: arr) {
            cnt[(x % k + k) % k]++;
        }
        for (int i = 1; i <= k / 2; i++) {
            if (i * 2 == k && cnt[i] & 1 || cnt[i] != cnt[k - i]) return false;
        }
        return !(cnt[0] & 1);
    }
};