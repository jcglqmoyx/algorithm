#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        int cnt[n];
        memset(cnt, 0, sizeof cnt);
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<>> available;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> used;
        for (int i = 0; i < n; i++) {
            available.emplace(i);
        }
        long long time = 0;
        for (auto &m: meetings) {
            long long start = m[0], end = m[1];
            time = max(time, start);
            while (!used.empty() && used.top().first <= time) {
                available.emplace(used.top().second);
                used.pop();
            }
            if (available.empty()) {
                auto t = used.top();
                used.pop();
                cnt[t.second]++;
                time = t.first;
                used.emplace(time + end - start, t.second);
            } else {
                auto t = available.top();
                available.pop();
                cnt[t]++;
                used.emplace(time + end - start, t);
            }
        }
        int mx = 0, res = 0;
        for (int i = 0; i < n; i++) {
            if (cnt[i] > mx) {
                mx = cnt[i];
                res = i;
            }
        }
        return res;
    }
};