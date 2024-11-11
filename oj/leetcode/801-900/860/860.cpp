#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int> &bills) {
        int cnt5 = 0, cnt10 = 0, cnt20 = 0;
        for (int b: bills) {
            if (b == 5) {
                cnt5++;
            } else if (b == 10) {
                if (!cnt5) return false;
                cnt5--;
                cnt10++;
            } else {
                if (cnt10 && cnt5) cnt10--, cnt5--;
                else if (cnt5 >= 3) cnt5 -= 3;
                else return false;
            }
        }
        return true;
    }
};