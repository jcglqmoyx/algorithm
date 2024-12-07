#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxCount(vector<int> &banned, int n, int maxSum) {
        int res = 0;
        unordered_set<int> s(banned.begin(), banned.end());
        for (int sum = 0, i = 1; i <= n; i++) {
            if (sum + i <= maxSum) {
                if (!s.contains(i)) {
                    sum += i;
                    res++;
                }
            } else {
                break;
            }
        }
        return res;
    }
};