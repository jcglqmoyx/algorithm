#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countTriplets(vector<int> &arr) {
        unordered_map<int, int> cnt, total;
        int res = 0;
        for (int s = 0, i = 0; i < arr.size(); i++) {
            int val = arr[i];
            if (cnt.count(s ^ val)) {
                res += cnt[s ^ val] * i - total[s ^ val];
            }
            cnt[s]++;
            total[s] += i;
            s ^= val;
        }
        return res;
    }
};