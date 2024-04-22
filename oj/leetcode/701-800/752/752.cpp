#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int openLock(vector<string> &deadends, string target) {
        unordered_set<string> st(deadends.begin(), deadends.end());
        if (st.contains("0000")) return -1;
        if (target == "0000") return 0;
        queue<string> q;
        int res = 0;
        q.emplace("0000");
        st.emplace("0000");
        while (!q.empty()) {
            res++;
            for (auto it = q.size(); it; it--) {
                auto t = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    string a = t;
                    a[i]--;
                    if (a[i] < '0') a[i] = '9';
                    if (!st.contains(a)) {
                        if (a == target) return res;
                        q.emplace(a);
                        st.emplace(a);
                    }
                    string b = t;
                    b[i]++;
                    if (b[i] > '9') b[i] = '0';
                    if (!st.contains(b)) {
                        if (b == target) return res;
                        q.emplace(b);
                        st.emplace(b);
                    }
                }
            }
        }
        return -1;
    }
};