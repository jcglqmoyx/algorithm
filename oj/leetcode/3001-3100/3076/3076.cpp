#include <bits/stdc++.h>


using namespace std;

class Solution {
public:
    vector<string> shortestSubstrings(vector<string> &arr) {
        auto n = arr.size();
        vector<string> res(n);
        for (int i = 0; i < n; i++) {
            string &s = arr[i];
            for (int len = 1; len <= s.size(); len++) {
                for (int from = 0; from + len - 1 < s.size(); from++) {
                    string t = s.substr(from, len);
                    bool ok = true;
                    for (int j = 0; j < n; j++) {
                        if (j != i) {
                            if (arr[j].contains(t)) {
                                ok = false;
                                break;
                            }
                        }
                    }
                    if (ok) {
                        if (res[i] == "" || t < res[i]) {
                            res[i] = t;
                        }
                    }
                }
                if (res[i] != "") {
                    break;
                }
            }
        }
        return res;
    }
};