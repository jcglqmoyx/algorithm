#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int> &hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize) return false;
        unordered_map<int, int> mp;
        for (int x: hand) mp[x]++;
        sort(hand.begin(), hand.end());
        for (int x: hand) {
            if (!mp.contains(x)) continue;
            for (int y = x; y <= x + groupSize - 1; y++) {
                if (!mp.contains(y)) return false;
                mp[y]--;
                if (mp[y] == 0) mp.erase(y);
            }
        }
        return true;
    }
};