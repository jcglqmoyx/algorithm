#include <bits/stdc++.h>

using namespace std;

/*
class Solution {
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes) {
        int res = minutes, n = customers.size();
        int s1[n + 1], s2[n + 1];
        s1[0] = s2[0] = 0;
        for (int i = 1; i <= n; i++) {
            s1[i] = s1[i - 1] + customers[i - 1];
            s2[i] = s2[i - 1] + customers[i - 1] * (grumpy[i - 1] ^ 1);
        }
        for (int l = 1; l + minutes - 1 <= n; l++) {
            int r = l + minutes - 1;
            res = max(res, s1[r] - s1[l - 1] + s2[l - 1] + s2[n] - s2[r]);
        }
        return res;
    }
};
 */

class Solution {
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes) {
        int res = minutes, n = customers.size();
        int left = 0, right = 0;
        for (int i = minutes; i < n; i++) {
            right += customers[i] * (grumpy[i] ^ 1);
        }
        for (int s = 0, l = 0, r = 0; r < n; r++) {
            s += customers[r];
            if (r >= minutes - 1) {
                res = max(res, left + s + right);
                s -= customers[l];
                if (r + 1 < n) right -= customers[r + 1] * (grumpy[r + 1] ^ 1);
                left += customers[l] * (grumpy[l] ^ 1);
                l++;
            }
        }
        return res;
    }
};
