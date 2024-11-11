#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches) {
        auto s1 = accumulate(students.begin(), students.end(), 0);
        int s0 = students.size() - s1;
        for (auto s: sandwiches) {
            if (s && s1) s1--;
            else if (!s && s0) s0--;
            else break;
        }
        return s0 + s1;
    }
};
