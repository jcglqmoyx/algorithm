#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int> &nums, int k) {
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
            if (j < n / 2) {
                partition(j + 1, r);
            } else if (j > n / 2) {
                partition(l, j - 1);
            }
        };

        partition(0, n - 1);

        long long res = 0;
        if (nums[n / 2] < k) {
            for (int i = n / 2; i < n; i++) {
                if (nums[i] < k) res += k - nums[i];
            }
        } else {
            for (int i = n / 2; i >= 0; i--) {
                if (nums[i] > k) res += nums[i] - k;
            }
        }
        return res;
    }
};