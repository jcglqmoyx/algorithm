#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int> &arr) {
        int res = 0, n = arr.size(), M = 1e9 + 7;
        int l[n], stk[n], tt = -1;
        for (int i = 0; i < n; i++) {
            while (~tt && arr[stk[tt]] >= arr[i]) tt--;
            l[i] = ~tt ? stk[tt] + 1 : 0;
            stk[++tt] = i;
        }
        tt = -1;
        for (int i = n - 1; i >= 0; i--) {
            while (~tt && arr[stk[tt]] > arr[i]) tt--;
            int ri = ~tt ? stk[tt] - 1 : n - 1;
            stk[++tt] = i;
            res = (res + (long long) (i - l[i] + 1) * (ri - i + 1) % M * arr[i]) % M;
        }
        return res;
    }
};