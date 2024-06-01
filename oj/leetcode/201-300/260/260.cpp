#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        int s = 0;
        for (int x: nums) s ^= x;
        int t = s;
        if (s != INT32_MIN) s = s & -s;
        int a = 0;
        for (int x: nums) {
            if (x & s) {
                a ^= x;
            }
        }
        return {a, t ^ a};
    }
};