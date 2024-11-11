#include <bits/stdc++.h>

using namespace std;

class Solution {
    string get(int x) {
        string s;
        while (x) {
            s.push_back((x & 1) + '0');
            x >>= 1;
        }
        reverse(s.begin(), s.end());
        return s;
    }

public:
    string convertDateToBinary(string date) {
        int y = stoi(date.substr(0, 4));
        int m = stoi(date.substr(5, 7));
        int d = stoi(date.substr(8));
        return get(y) + '-' + get(m) + '-' + get(d);
    }
};