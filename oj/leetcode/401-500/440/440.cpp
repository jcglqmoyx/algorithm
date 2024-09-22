#include <bits/stdc++.h>

using namespace std;

class Solution {
    int get(int x, long long n) {
        int cnt = 0;
        long long first = x, last = x;
        while (first <= n) {
            cnt += min(last, n) - first + 1;
            first *= 10, last = last * 10 + 9;
        }
        return cnt;
    }

public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        k--;
        while (k) {
            int t = get(cur, n);
            if (t <= k) k -= t, cur++;
            else k--, cur *= 10;
        }
        return cur;
    }
};