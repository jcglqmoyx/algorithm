#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int> &servers, vector<int> &tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> available;
        struct Server {
            int next_available_time;
            int weight;
            int idx;

            bool operator<(const Server &t) const {
                if (next_available_time == t.next_available_time) {
                    if (weight == t.weight) {
                        return idx > t.idx;
                    }
                    return weight > t.weight;
                }
                return next_available_time > t.next_available_time;
            }
        };

        priority_queue<Server> occupied;
        for (int i = 0; i < servers.size(); i++) {
            available.emplace(servers[i], i);
        }
        auto n = tasks.size();
        vector<int> res(n);
        for (int time = 0, i = 0; i < n; i++) {
            time = max(time, i);
            while (!occupied.empty() && occupied.top().next_available_time <= time) {
                auto t = occupied.top();
                occupied.pop();
                available.emplace(t.weight, t.idx);
            }
            if (available.empty()) {
                auto t = occupied.top();
                occupied.pop();
                time = t.next_available_time;
                occupied.emplace(time + tasks[i], t.weight, t.idx);
                res[i] = t.idx;
            } else {
                auto t = available.top();
                available.pop();
                occupied.emplace(time + tasks[i], servers[t.second], t.second);
                res[i] = t.second;
            }
        }
        return res;
    }
};