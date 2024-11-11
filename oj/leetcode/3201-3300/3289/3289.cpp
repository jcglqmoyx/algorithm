#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int> &nums) {
        int n = nums.size() - 2;
        int a = -n * (n - 1) / 2;
        int b = -n * (n - 1) * (n * 2 - 1) / 6;
        for (int x: nums) {
            a += x;
            b += x * x;
        }
        int x = (a - sqrt(b * 2 - a * a)) / 2;
        return {x, a - x};
    }
};