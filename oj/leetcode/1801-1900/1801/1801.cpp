#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>> &orders) {
        const int MOD = 1e9 + 7;
        priority_queue<vector<int>> buy;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> sell;
        for (auto &o: orders) {
            if (o[2] == 0) {
                while (!sell.empty()) {
                    auto t = sell.top();
                    if (t[0] > o[0]) {
                        break;
                    }
                    sell.pop();
                    int minus = min(t[1], o[1]);
                    t[1] -= minus, o[1] -= minus;
                    if (!o[1]) {
                        if (t[1]) {
                            sell.emplace(t);
                        }
                        break;
                    }
                }
                if (o[1]) {
                    buy.emplace(o);
                }
            } else {
                while (!buy.empty()) {
                    auto t = buy.top();
                    if (t[0] < o[0]) {
                        break;
                    }
                    buy.pop();
                    int minus = min(t[1], o[1]);
                    t[1] -= minus, o[1] -= minus;
                    if (!o[1]) {
                        if (t[1]) {
                            buy.emplace(t);
                        }
                        break;
                    }
                }
                if (o[1]) {
                    sell.emplace(o);
                }
            }
        }
        int res = 0;
        while (!buy.empty()) {
            res += buy.top()[1];
            buy.pop();
            if (res > MOD) res -= MOD;
        }
        while (!sell.empty()) {
            res += sell.top()[1];
            sell.pop();
            if (res > MOD) res -= MOD;
        }
        return res;
    }
};