#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKthPositive(vector<int> &arr, int k) {
        for (int i = 1; i <= arr.size(); i++) {
            if (arr[i - 1] - i >= k) {
                if (i == 1) return k;
                else return k + i - 1;
            }
        }
        return k + arr.size();
    }
};