#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countTestedDevices(vector<int> &batteryPercentages) {
        int res = 0;
        for (int x: batteryPercentages) {
            if (x > res) res++;
        }
        return res;
    }
};