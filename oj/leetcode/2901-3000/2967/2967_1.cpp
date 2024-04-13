#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool is_palindrome(int x) {
        vector<int> v;
        while (x) v.emplace_back(x % 10), x /= 10;
        for (int i = 0; i < v.size() / 2; i++) {
            if (v[i] != v[v.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }

    long long get(vector<int> &nums, int x) {
        long long res = 0;
        for (int num: nums) {
            res += abs(num - x);
        }
        return res;
    }

public:
    long long minimumCost(vector<int> &nums) {
        long long res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int median = nums[n / 2];
        for (int i = median; i >= 1; i--) {
            if (is_palindrome(i)) {
                res = get(nums, i);
                break;
            }
        }
        for (int i = median + 1;; i++) {
            if (is_palindrome(i)) {
                res = min(res, get(nums, i));
                break;
            }
        }
        return res;
    }
};