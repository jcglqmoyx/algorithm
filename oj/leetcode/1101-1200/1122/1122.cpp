#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
        vector<int> res;
        unordered_map<int, int> p;
        for (int i = 0; i < arr2.size(); i++) {
            p[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(), [&](int a, int b) {
            if (p.contains(a) && p.contains(b)) return p[a] < p[b];
            if (p.contains(a)) return true;
            else if (p.contains(b)) return false;
            return a < b;
        });
        return arr1;
    }
};