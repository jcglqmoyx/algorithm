#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int> &hours, int target) {
        int res = 0;
        for (int x: hours) {
            if (x >= target) {
                res++;
            }
        }
        return res;
    }
};