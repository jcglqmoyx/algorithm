#include <bits/stdc++.h>

#include <utility>

using namespace std;

struct Node {
    string val;
    bool is_end;
    unordered_map<string, Node *> ne;

    explicit Node(string _val) {
        this->val = std::move(_val);
        this->is_end = false;
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string> &folder) {
        sort(folder.begin(), folder.end());
        auto root = new Node("/");
        vector<string> res;
        for (auto &f: folder) {
            auto p = root;
            bool valid = true;
            for (int prev = 0, i = 1; i < f.size(); i++) {
                if (i < f.size() && f[i + 1] == '/' || i == f.size() - 1) {
                    string s = f.substr(prev, i - prev + 1);
                    if (p->ne.contains(s)) {
                        if (p->ne[s]->is_end) {
                            valid = false;
                            break;
                        }
                    } else {
                        p->ne[s] = new Node(s);
                    }
                    p = p->ne[s];
                }
            }
            if (valid) {
                p->is_end = true;
                res.emplace_back(f);
            }
        }
        delete root;
        return res;
    }
};