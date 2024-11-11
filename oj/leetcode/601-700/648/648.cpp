#include <bits/stdc++.h>

using namespace std;

const int N = 2600010;

int tr[N][26], idx;
bool is_end[N];

void insert(string &s) {
    int p = 0;
    for (char c: s) {
        int u = c - 'a';
        if (!tr[p][u]) tr[p][u] = ++idx;
        p = tr[p][u];
    }
    is_end[p] = true;
}

class Solution {
public:
    string replaceWords(vector<string> &dictionary, string sentence) {
        memset(is_end, 0, sizeof is_end);
        for (auto &d: dictionary) {
            insert(d);
        }
        stringstream ss(sentence);
        string s;
        string res;
        while (ss >> s) {
            bool flag = true;
            int p = 0;
            for (int i = 0; i < s.size(); i++) {
                int u = s[i] - 'a';
                if (!tr[p][u]) break;
                else p = tr[p][u];
                if (is_end[p]) {
                    res += s.substr(0, i + 1);
                    flag = false;
                    break;
                }
            }
            if (flag) res += s;
            res.push_back(' ');
        }
        res.pop_back();
        return res;
    }
};