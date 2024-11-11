#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int> &nums, int k) {
        int res = 0;
        int s = 0;
        for (int x: nums) {
            s ^= x;
        }
        for (int i = 0; i < 20; i++) {
            if ((s >> i & 1) != (k >> i & 1)) {
                res++;
            }
        }
        return res;
    }
};