#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int> &nums) {
        int res = 0;
        for (int x: nums) {
            if (x % 3) res++;
        }
        return res;
    }
};