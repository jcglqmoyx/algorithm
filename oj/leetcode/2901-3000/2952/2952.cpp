#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int minimumAddedCoins(vector<int> &coins, int target) {
        sort(coins.begin(), coins.end());
        int res = 0, s = 1, i = 0;
        while (s <= target) {
            if (i < coins.size() && coins[i] <= s) {
                s += coins[i++];
            } else {
                s <<= 1;
                res++;
            }
        }
        return res;
    }
};