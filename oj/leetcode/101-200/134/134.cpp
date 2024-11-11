#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        auto n = gas.size();
        for (int i = 0; i < n;) {
            int g = 0, c = 0;
            int cnt = 0;
            while (cnt < n) {
                int j = (i + cnt) % n;
                g += gas[j], c += cost[j];
                if (g < c) break;
                cnt++;
            }
            if (cnt == n) return i;
            else i = i + cnt + 1;
        }
        return -1;
    }
};