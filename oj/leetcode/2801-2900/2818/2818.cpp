#include <bits/stdc++.h>

using namespace std;

class Solution {
    const int MOD = 1e9 + 7;

    long long power(long long x, int n) {
        long long res = 1;
        while (n) {
            if (n & 1) res = res * x % MOD;
            x = x * x % MOD;
            n >>= 1;
        }
        return res;
    }

public:
    int maximumScore(vector<int> &nums, int k) {
        int n = nums.size();
        int score[n];
        memset(score, 0, sizeof score);
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int a = 2; a * a <= x; a++) {
                if (x % a == 0) {
                    score[i]++;
                    while (x % a == 0) {
                        x /= a;
                    }
                }
            }
            if (x > 1) {
                score[i]++;
            }
        }
        int stk[n];
        int l[n], r[n];
        for (int tt = -1, i = 0; i < n; i++) {
            while (~tt && score[stk[tt]] < score[i]) tt--;
            l[i] = ~tt ? stk[tt] + 1 : 0;
            stk[++tt] = i;
        }
        for (int tt = -1, i = n - 1; ~i; i--) {
            while (~tt && score[stk[tt]] <= score[i]) tt--;
            r[i] = ~tt ? stk[tt] - 1 : n - 1;
            stk[++tt] = i;
        }
        int id[n];
        iota(id, id + n, 0);
        sort(id, id + n, [&](int i, int j) {
            return nums[i] > nums[j];
        });
        long long res = 1;
        for (int i = 0; i < n && k; i++) {
            long long left = id[i] - l[id[i]] + 1, right = r[id[i]] - id[i] + 1;
            long long t = min((long long) k, left * right);
            res = res * power(nums[id[i]], t) % MOD;
            k -= t;
        }
        return res;
    }
};