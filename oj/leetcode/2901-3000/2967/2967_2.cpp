#include <bits/stdc++.h>

using namespace std;

class Solution {
    static long long get_sum(vector<int> &nums, int x) {
        long long res = 0;
        for (int e: nums) {
            res += abs(e - x);
        }
        return res;
    }

    static bool is_palindrome(string &s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }

public:
    long long minimumCost(vector<int> &nums) {
        long long res;
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];
        string s = to_string(median);
        if (is_palindrome(s)) return get_sum(nums, median);

        if (s[0] == '1') {
            bool ok = true;
            for (int i = 1; i < s.size(); i++) {
                if (s[i] - '0') {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                return min(get_sum(nums, median - 1), get_sum(nums, median + 1));
            }
        }

        int n = s.size();
        int l = 0;
        for (int i = 0; i < (n + 1) / 2; i++) {
            l = l * 10 + s[i] - '0';
        }
        int t = l;
        for (int i = (n + 1) / 2; i < n; i++) {
            s[i] = s[n - i - 1];
            t = t * 10 + s[i] - '0';
        }
        res = get_sum(nums, t);

        if (t > median) l--;
        else l++;
        t = l;
        string sl = to_string(l);

        for (int i = sl.size() - 1 - (n & 1); i >= 0; i--) {
            t = t * 10 + sl[i] - '0';
        }
        res = min(res, get_sum(nums, t));
        return res;
    }
};