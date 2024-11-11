#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countTriplets(vector<int> &arr) {
        int res = 0;
        for (int s = 0, r = 0; r < arr.size(); r++) {
            s ^= arr[r];
            unordered_map<int, int> cnt;
            cnt[0] = 1;
            for (int t = 0, l = 0; l < r; l++) {
                t ^= arr[l];
                res += cnt[s];
                cnt[t]++;
            }
        }
        return res;
    }
};