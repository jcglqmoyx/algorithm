#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital) {
        int n = profits.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) v[i] = {capital[i], profits[i]};
        sort(v.begin(), v.end());
        priority_queue<int> q;
        int i = 0;
        while (k) {
            while (i < n && v[i].first <= w) {
                q.emplace(v[i].second);
                i++;
            }
            if (q.empty()) break;
            w += q.top();
            q.pop();
            k--;
        }
        return w;
    }
};