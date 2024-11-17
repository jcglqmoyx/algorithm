#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int> &ages) {
        const int N = 121;
        int cnt[N]{}, s[N]{};
        for (int x: ages) {
            cnt[x]++;
        }
        for (int i = 1; i < N; i++) {
            s[i] = s[i - 1] + cnt[i];
        }
        int res = 0;
        for (int x = 1; x < N; x++) {
            if (x > x / 2 + 7) res += cnt[x] * ((s[x - 1] - s[x / 2 + 7]) + cnt[x] - 1);
        }
        return res;
    }
};