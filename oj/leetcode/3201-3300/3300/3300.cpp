#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minElement(vector<int> &nums) {
        int res = 36;
        for (int x: nums) {
            int s = 0;
            while (x) {
                s += x % 10;
                x /= 10;
            }
            res = min(res, s);
        }
        return res;
    }
};