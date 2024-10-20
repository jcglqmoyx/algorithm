#include <bits/stdc++.h>

using namespace std;

const int N = 1000001;

int divide_by_proper_divisor[N];
int pm[N >> 1], idx;

int init = []() {
    memset(divide_by_proper_divisor, -1, sizeof divide_by_proper_divisor);
    for (int i = 2; i < N; i++) {
        if (divide_by_proper_divisor[i] == -1) {
            pm[idx++] = i;
            divide_by_proper_divisor[i] = i;
        }
        for (int j = 0; pm[j] * i < N; j++) {
            divide_by_proper_divisor[pm[j] * i] = min(i, pm[j]);
            if (i % pm[j] == 0) break;
        }
    }
    return 0;
}();

class Solution {
public:
    int minOperations(vector<int> &nums) {
        int res = 0;
        for (int mn = 1e9, i = static_cast<int>(nums.size()) - 1; i >= 0; i--) {
            int x = nums[i];
            if (x > mn) {
                x = divide_by_proper_divisor[x];
                if (x > mn) return -1;
                res++;
            }
            mn = min(mn, x);
        }
        return res;
    }
};