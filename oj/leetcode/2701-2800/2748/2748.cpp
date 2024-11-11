#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y) {
    return x % y == 0 ? y : gcd(y, x % y);
}

class Solution {
public:
    int countBeautifulPairs(vector<int> &nums) {
        vector<vector<int>> memo(10);
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                if (gcd(i, j) == 1) {
                    memo[i].emplace_back(j);
                }
            }
        }
        int cnt[10]{};
        int res = 0;
        for (int x: nums) {
            int first = 0, last = x % 10;
            for (int a: memo[last]) {
                res += cnt[a];
            }
            while (x) {
                first = x % 10;
                x /= 10;
            }
            cnt[first]++;
        }
        return res;
    }
};