#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches) {
        deque<int> q;
        for (int student: students) q.emplace_back(student);
        for (int sandwich: sandwiches) {
            bool flag = false;
            for (auto it = q.size(); it; it--) {
                int t = q.front();
                q.pop_front();
                if (t == sandwich) {
                    flag = true;
                    break;
                } else {
                    q.emplace_back(t);
                }
            }
            if (!flag) break;
        }
        return q.size();
    }
};