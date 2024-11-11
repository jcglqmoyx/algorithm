#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k) {
        double l = 0, r = 1;
        int n = arr.size();
        auto check = [&](double mid) {
            int cnt = 0;
            for (int i = 0, j = 1; i + 1 < n && j < n; i++) {
                while (j < n && (double) arr[i] / arr[j] > mid) j++;
                cnt += n - j;
            }
            return cnt >= k;
        };
        while (abs(l - r) > 1e-7) {
            auto mid = (l + r) / 2;
            if (check(mid)) r = mid;
            else l = mid;
        }
        int a = 0, b = 1;
        for (int i = 0, j = 1; i < n - 1 && j < n; i++) {
            while (j < n && abs((double) arr[i] / arr[j] - l) > 1e-7 && (double) arr[i] / arr[j] > l) j++;
            if (j == n) break;
            if (a * arr[j] < b * arr[i]) a = arr[i], b = arr[j];
        }
        return {a, b};
    }
};