#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> s;
        for (int x: nums) {
            if (s.find(x) != s.end()) {
                return true;
            }
            s.emplace(x);
        }
        return false;
    }
};