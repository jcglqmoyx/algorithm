#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int> &arr) {
        unordered_set<int> set;
        for (int x: arr) {
            if (!(x & 1) && set.contains(x / 2) || set.contains(x * 2)) {
                return true;
            }
            set.emplace(x);
        }
        return false;
    }
};