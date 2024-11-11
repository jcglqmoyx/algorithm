#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumPoints(vector<int> &enemyEnergies, int currentEnergy) {
        int mn = *min_element(enemyEnergies.begin(), enemyEnergies.end());
        if (mn > currentEnergy) {
            return 0;
        }
        long long e = currentEnergy - mn * 2;
        for (int energy: enemyEnergies) {
            e += energy;
        }
        return e / mn + 1;
    }
};