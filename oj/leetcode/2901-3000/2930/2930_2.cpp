#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dp[50][50]{};

    const int mm = 1e9 + 7;

    void search(span<int> s, int power, int n, vector<int> &ret) {
        int k = -1;

        for (int i = 1; i < s.size(); ++i) {
            while (k < i - 1 && abs(s[i] - s[k + 1]) >= power) {
                k++;
            }

            int j1 = min(i + 1, n);
            for (int j = 1; j <= j1; ++j) {
                dp[i + 1][j] = dp[i][j] + dp[k + 1][j - 1];
                dp[i + 1][j] %= mm;
            }
        }

        for (int j = 2; j <= s.size() && j <= n; ++j) {
            ret[j] = dp[s.size()][j];
        }
    }

    int sumOfPowers(vector<int> &nums, int n) {
        std::sort(nums.begin(), nums.end());

        auto reversed = nums;
        std::reverse(reversed.begin(), reversed.end());

        vector<int> dp0(n), dp1(n);
        dp[1][1] = 1;
        dp0[1] = 1;
        dp1[1] = 1;

        long long ret = 0;

        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                int power = nums[j] - nums[i];
                span left(&reversed[nums.size() - i - 1], i + 1);
                span right(&nums[j], nums.size() - j);

                if (left.size() + right.size() >= n) {
                    search(left, power + 1, n - 1, dp0);
                    search(right, power, n - 1, dp1);

                    for (int k = 1; k <= left.size() && k < n; ++k) {
                        if (n - k <= right.size()) {
                            ret += (long long) power * dp0[k] * dp1[n - k];
                            ret %= mm;
                        }
                    }
                }
            }
        }
        return ret;
    }
};