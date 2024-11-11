#include <bits/stdc++.h>

using namespace std;

class MyCalendar {
    set<pair<int, int>> records;
public:
    MyCalendar() {
        records.emplace(-1, -1);
    }

    bool book(int start, int end) {
        auto it = records.lower_bound({start, -1});
        if (it != records.end() && end > (*it).first || (--it)->second > start) return false;
        records.emplace(start, end);
        return true;
    }
};