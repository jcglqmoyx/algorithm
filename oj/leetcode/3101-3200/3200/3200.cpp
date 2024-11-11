#include <bits/stdc++.h>

using namespace std;

class Solution {
    int get(int a, int b) {
        int r1 = sqrt(4 * a);
        int r2 = sqrt(1 + 4 * b) - 1;
        if (a - r1 * r1 / 4 > r1) r1++;
        if (a - r2 * r2 / 4 > r2) r2++;
        return min(r1, r2);
    }

public:
    int maxHeightOfTriangle(int red, int blue) {
        if (max(red, blue) == 1) return 1;
        return max(get(red, blue), get(blue, red));
    }
};