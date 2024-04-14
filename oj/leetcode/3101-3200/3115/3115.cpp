#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumPrimeDifference(vector<int> &nums) {
        bool st[101]{};
        int p[101], idx = 0;
        for (int i = 2; i <= 100; i++) {
            if (!st[i]) p[idx++] = i;
            for (int j = 0; p[j] * i <= 100; j++) {
                st[p[j] * i] = true;
                if (i % p[j] == 0) break;
            }
        }
        st[1] = true;
        int first, last;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (!st[nums[i]]) {
                first = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (!st[nums[i]]) {
                last = i;
                break;
            }
        }
        return last - first;
    }
};