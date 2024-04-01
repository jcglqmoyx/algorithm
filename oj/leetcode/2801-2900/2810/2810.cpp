#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static string finalString(string s) {
        deque<char> q;
        bool reversed = false;
        for (char c: s) {
            if (c == 'i') {
                reversed = !reversed;
                continue;
            }
            if (reversed) {
                q.push_front(c);
            } else {
                q.push_back(c);
            }
        }
        string res;
        if (reversed) {
            while (!q.empty()) {
                res.push_back(q.back());
                q.pop_back();
            }
        } else {
            while (!q.empty()) {
                res.push_back(q.front());
                q.pop_front();
            }
        }
        return res;
    }
};