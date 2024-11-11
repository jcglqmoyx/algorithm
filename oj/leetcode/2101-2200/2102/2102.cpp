#include <bits/stdc++.h>

using namespace std;

class SORTracker {
    struct T1 {
        int score;
        string name;

        bool operator<(const T1 &t) const {
            if (score == t.score) return name < t.name;
            return score > t.score;
        }
    };

    struct T2 {
        int score;
        string name;

        bool operator<(const T2 &t) const {
            if (score == t.score) return name > t.name;
            return score < t.score;
        }
    };

    int idx = 1;
    priority_queue<T1> q1;
    priority_queue<T2> q2;

public:
    SORTracker() {
    }

    void add(string name, int score) {
        q1.emplace(score, name);
    }

    string get() {
        while (q1.size() > idx - 1) {
            auto t = q1.top();
            q2.emplace(t.score, t.name);
            q1.pop();
        }
        while (q1.size() < idx) {
            auto t = q2.top();
            q2.pop();
            q1.emplace(t.score, t.name);
        }
        idx++;
        return q1.top().name;
    }
};