#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumRefill(vector<int> &plants, int capacityA, int capacityB) {
        int refill = 0;
        for (int a = capacityA, b = capacityB, i = 0, j = plants.size() - 1; i <= j; i++, j--) {
            if (i == j) {
                if (max(a, b) < plants[i]) refill++;
            } else {
                if (a < plants[i]) a = capacityA - plants[i], refill++;
                else a -= plants[i];

                if (b < plants[j]) b = capacityB - plants[j], refill++;
                else b -= plants[j];
            }
        }
        return refill;
    }
};