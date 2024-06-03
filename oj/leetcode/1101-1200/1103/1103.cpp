#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int last = ((int) sqrt(1 + 8LL * candies) - 1) / 2;
        int c = last / num_people;
        vector<int> res(num_people);
        if (c) {
            for (int start = (1 + (c - 1) * num_people + 1) * c / 2, i = 0; i < num_people && candies; i++) {
                res[i] = min(start + c * i, candies);
                candies -= res[i];
            }
        }
        for (int x = c * num_people + 1, i = 0; i < num_people && candies; i++, x++) {
            int t = min(x, candies);
            res[i] += t;
            candies -= t;
        }
        return res;
    }
};