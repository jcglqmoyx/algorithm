#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        int x1 = INT_MIN, x2 = INT_MIN, cnt1 = 0, cnt2 = 0;
        for (int x: nums) {
            if (x == x1) {
                cnt1++;
            } else if (x == x2) {
                cnt2++;
            } else if (cnt1 == 0) {
                cnt1++;
                x1 = x;
            } else if (cnt2 == 0) {
                cnt2++;
                x2 = x;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        vector<int> majority;
        cnt1 = 0, cnt2 = 0;
        for (int x: nums) {
            if (x == x1) cnt1++;
            else if (x == x2) cnt2++;
        }
        if (cnt1 > nums.size() / 3) majority.emplace_back(x1);
        if (cnt2 > nums.size() / 3) majority.emplace_back(x2);
        return majority;
    }
};