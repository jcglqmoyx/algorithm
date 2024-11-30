#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canAliceWin(vector<int> &nums) {
        int s = 0;
        for (int x: nums) {
            s += x < 10 ? x : -x;
        }
        return s;
    }
};