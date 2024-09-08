#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int smallestChair(vector<vector<int>> &times, int targetFriend) {
        int start = times[targetFriend][0];
        int n = times.size();
        pair<int, int> t[n << 1];
        for (int u = 0, i = 0; i < n; i++) {
            t[u++] = {times[i][0], i};
            t[u++] = {-times[i][1], i};
        }
        sort(t, t + n * 2, [](auto a, auto b) {
            int x = abs(a.first), y = abs(b.first);
            if (x == y) return a.first < b.first;
            return x < y;
        });
        set<int> s;
        for (int i = 0; i < n; i++) {
            s.emplace(i);
        }
        unordered_map<int, int> map;
        for (int i = 0; i < n * 2; i++) {
            auto [time, idx] = t[i];
            if (time < 0) {
                s.emplace(map[idx]);
            } else {
                if (idx == targetFriend) {
                    return *s.begin();
                }
                map[idx] = *s.begin();
                s.erase(s.begin());
            }
        }
        return 0;
    }
};