#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int pm[N / 2], idx;
bool st[N];

int init = []() {
    memset(st, 0, sizeof st);
    pm[0] = 0;
    idx = 1;
    for (int i = 2; i < N; i++) {
        if (!st[i]) {
            pm[idx++] = i;
        }
        for (int j = 1; pm[j] * i < N; j++) {
            st[pm[j] * i] = true;
            if (i % pm[j] == 0) {
                break;
            }
        }
    }
    return 0;
}();

class Solution {
public:
    bool primeSubOperation(vector<int> &nums) {
        for (int mx = nums.back(), i = static_cast<int>(nums.size()) - 2; i >= 0; i--) {
            int l = 0, r = idx - 1;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (nums[i] - pm[mid] >= mx) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            if (pm[l] >= nums[i]) {
                return false;
            }
            mx = nums[i] - pm[l];
        }
        return true;
    }
};