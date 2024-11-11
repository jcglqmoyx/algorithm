#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k) {
        struct T {
            int i, j;
            int x, y;

            bool operator<(const T &t) const {
                return x * t.y > y * t.x;
            }
        };
        priority_queue<T> q;
        for (int i = 0; i + 1 < arr.size(); i++) {
            q.emplace(i, arr.size() - 1, arr[i], arr[arr.size() - 1]);
        }
        while (k-- > 1) {
            auto t = q.top();
            q.pop();
            if (t.j - t.i > 1) {
                q.emplace(t.i, t.j - 1, arr[t.i], arr[t.j - 1]);
            }
        }
        return {q.top().x, q.top().y};
    }
};