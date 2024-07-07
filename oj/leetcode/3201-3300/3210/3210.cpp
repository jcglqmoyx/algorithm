#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string getEncryptedString(string s, int k) {
        k %= s.size();
        return s.substr(k) + s.substr(0, k);
    }
};
