#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int> &arr) {
        for (int i = 0; i + 2 < arr.size(); i++) {
            if (arr[i] & 1) {
                int j = i + 1;
                while (j <= i + 2 && arr[j] & 1) j++;
                if (j == i + 3) return true;
                i = j - 1;
            }
        }
        return false;
    }
};