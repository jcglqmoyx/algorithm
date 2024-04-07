#include <bits/stdc++.h>

using namespace std;

class ThroneInheritance {
    string king;
    unordered_set<string> dead;
    unordered_map<string, vector<string>> map;
    vector<string> order;

    void dfs(string &cur) {
        if (!dead.contains(cur)) {
            order.emplace_back(cur);
        }
        for (auto &child: map[cur]) {
            dfs(child);
        }
    }

public:
    ThroneInheritance(string kingName) {
        map[kingName] = {};
        king = std::move(kingName);
    }

    void birth(string parentName, string childName) {
        map[std::move(parentName)].emplace_back(std::move(childName));
    }

    void death(string name) {
        dead.emplace(std::move(name));
    }

    vector<string> getInheritanceOrder() {
        order.clear();
        dfs(king);
        return order;
    }
};