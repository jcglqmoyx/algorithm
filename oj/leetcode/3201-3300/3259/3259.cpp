#include <bits/stdc++.h>

using namespace std;

/*
class Solution {
public:
    long long maxEnergyBoost(vector<int> &energyDrinkA, vector<int> &energyDrinkB) {
        int n = energyDrinkA.size();
        long long f[n + 1][2];
        memset(f, 0, sizeof f);
        f[0][0] = f[0][1] = 0;
        f[1][0] = energyDrinkA[0], f[1][1] = energyDrinkB[0];
        for (int i = 2; i <= n; i++) {
            f[i][0] = max(f[i - 1][0] + energyDrinkA[i - 1], f[i - 2][1] + energyDrinkA[i - 1]);
            f[i][1] = max(f[i - 1][1], f[i - 2][0]) + energyDrinkB[i - 1];
        }
        return max(f[n][0], f[n][1]);
    }
};
 */

class Solution {
public:
    long long maxEnergyBoost(vector<int> &energyDrinkA, vector<int> &energyDrinkB) {
        int n = energyDrinkA.size();
        long long a0 = 0, b0 = 0, a1 = energyDrinkA[0], b1 = energyDrinkB[0];
        for (int i = 1; i < n; i++) {
            long long a2 = max(a1, b0) + energyDrinkA[i];
            long long b2 = max(b1, a0) + energyDrinkB[i];
            a0 = a1, b0 = b1, a1 = a2, b1 = b2;
        }
        return max(a1, b1);
    }
};