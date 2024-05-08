#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int wateringPlants(vector<int> &plants, int capacity) {
        int res = 0;
        for (int i = 0, t = capacity; i < plants.size(); i++) {
            if (t < plants[i]) t = capacity - plants[i], res += i + i + 1;
            else t -= plants[i], res++;
        }
        return res;
    }
};