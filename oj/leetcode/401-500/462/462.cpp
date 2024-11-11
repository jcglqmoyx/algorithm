#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int> &nums) {
        int n = nums.size();
        function<void(int, int)> partition = [&](int l, int r) {
            if (l >= r) return;
            int idx = l + rand() % (r - l + 1);
            swap(nums[l], nums[idx]);
            int pivot = nums[l];
            int i = l + 1, j = r;
            while (true) {
                while (i < r && nums[i] < pivot) i++;
                while (j > l && nums[j] > pivot) j--;
                if (i >= j) break;
                swap(nums[i], nums[j]);
                i++, j--;
            }
            swap(nums[l], nums[j]);
            if (j < n / 2) partition(j + 1, r);
            else if (j > n / 2) partition(l, j - 1);
        };
        partition(0, n - 1);
        int res = 0, median = nums[n / 2];
        for (int i = 0; i < n / 2; i++) {
            res += median - nums[i];
        }
        for (int i = n / 2 + 1; i < n; i++) {
            res += nums[i] - median;
        }
        return res;
    }
};