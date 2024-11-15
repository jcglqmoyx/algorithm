#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int> &arr) {
        int n = static_cast<int>(arr.size());
        bool r[n];
        r[n - 1] = true;
        int res = n;
        for (int i = n - 2; i >= 0; i--) {
            r[i] = r[i + 1] & (arr[i] <= arr[i + 1]);
            if (r[i]) {
                res = i;
            }
        }
        if (!res) {
            return res;
        }
        for (int prev = -1, i = 0, j = 1; i < n; i++) {
            if (arr[i] < prev) {
                break;
            }
            while (j < n && (!r[j] || arr[j] < arr[i])) j++;
            res = min(res, j - i - 1);
            prev = arr[i];
        }
        return res;
    }
};