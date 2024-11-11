#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int> &nums) {
        auto n = nums.size();
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= 0) r = mid;
            else l = mid + 1;
        }
        vector<int> res(n);
        int i = l - 1, j = l;
        cout << i << " " << j << endl;
        for (int u = 0; u < n; u++) {
            if (i >= 0 && j < n) {
                if (-nums[i] <= nums[j]) res[u] = nums[i] * nums[i], i--;
                else res[u] = nums[j] * nums[j], j++;
            } else if (i >= 0) {
                res[u] = nums[i] * nums[i], i--;
            } else {
                res[u] = nums[j] * nums[j], j++;
            }
        }
        return res;
    }
};
