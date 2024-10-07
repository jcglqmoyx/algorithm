#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations) {
        stations.emplace_back(vector<int>{target, 0});
        int res = 0, s = startFuel;
        priority_queue<int> heap;
        for (auto &station: stations) {
            while (!heap.empty() && s < station[0]) {
                s += heap.top();
                heap.pop();
                res++;
            }
            if (s < station[0]) return -1;
            heap.emplace(station[1]);
        }
        return res;
    }
};