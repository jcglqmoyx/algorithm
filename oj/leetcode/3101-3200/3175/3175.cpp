#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findWinningPlayer(vector<int> &skills, int k) {
        int x = skills[0], p = 0;
        for (int cnt = 0, i = 1; i < skills.size(); i++) {
            if (skills[i] > x) {
                x = skills[i];
                p = i;
                cnt = 1;
            } else {
                cnt++;
            }
            if (cnt == k) return p;
        }
        return p;
    }
};