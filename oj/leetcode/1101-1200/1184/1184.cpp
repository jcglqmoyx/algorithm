#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int distanceBetweenBusStops(vector<int> &distance, int start, int destination) {
        if (start > destination) swap(start, destination);
        int a = accumulate(distance.begin() + start, distance.begin() + destination, 0);
        int b = accumulate(distance.begin() + destination, distance.end(),
                           0 + accumulate(distance.begin(), distance.begin() + start, 0));
        return min(a, b);
    }
};