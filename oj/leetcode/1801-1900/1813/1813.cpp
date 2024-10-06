#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> v1, v2;
        string w;
        stringstream ss1(sentence1), ss2(sentence2);
        while (ss1 >> w) v1.emplace_back(w);
        while (ss2 >> w) v2.emplace_back(w);
        if (v1.size() > v2.size()) swap(v1, v2);
        int l = -1;
        while (l + 1 < v1.size()) {
            if (v1[l + 1] == v2[l + 1]) l++;
            else break;
        }
        if (l + 1 == sentence1.size()) return true;
        int r = v1.size(), u = v2.size() - 1;
        while (r - 1 >= 0 && u - 1 >= 0) {
            if (v1[r - 1] == v2[u]) r--, u--;
            else break;
        }
        return l + 1 >= r;
    }
};