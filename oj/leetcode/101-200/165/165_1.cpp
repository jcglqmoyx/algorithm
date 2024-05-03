#include <bits/stdc++.h>

using namespace std;

class Solution {
    string trim(string s) {
        int i = 0;
        while (i < s.size() && s[i] == '0') i++;
        if (i == s.size()) return "0";
        int j = s.size() - 1;
        return s.substr(i, j - i + 1);
    }

    vector<string> get(string &s) {
        vector<string> res;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                int j = i + 1;
                while (j < s.size() && isdigit(s[j])) j++;
                string x = trim(s.substr(i, j - i));
                res.emplace_back(x);
                i = j;
            }
        }
        while (res.size() > 1 && res.back() == "0") res.pop_back();
        return res;
    }

    int cmp(string &s, string &t) {
        if (s.size() < t.size()) return -1;
        else if (s.size() > t.size()) return 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] > t[i]) return 1;
            else if (s[i] < t[i]) return -1;
        }
        return 0;
    }

public:
    int compareVersion(string version1, string version2) {
        vector<string> v1 = get(version1), v2 = get(version2);
        int i = 0, j = 0;
        while (i < v1.size() && j < v2.size()) {
            int t = cmp(v1[i], v2[j]);
            if (t == 1) return 1;
            else if (t == -1) return -1;
            i++, j++;
        }
        if (i == v1.size() && j == v2.size()) return 0;
        if (i == v1.size()) return -1;
        return 1;
    }
};