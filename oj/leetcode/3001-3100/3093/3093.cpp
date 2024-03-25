#include <bits/stdc++.h>

using namespace std;

struct Trie {
    Trie* son[26];
    int min_length = 1e9, index;

    ~Trie() {
        for (auto&child: son) {
            delete child;
        }
    }

    void insert(string&s, int idx) {
        auto cur = this;
        int n = s.size();
        if (n < cur->min_length) cur->min_length = n, cur->index = idx;
        for (int i = n - 1; i >= 0; i--) {
            int u = s[i] - 'a';
            if (!cur->son[u]) cur->son[u] = new Trie();
            cur = cur->son[u];
            if (n < cur->min_length) cur->min_length = n, cur->index = idx;
        }
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>&wordsContainer, vector<string>&wordsQuery) {
        auto trie = new Trie();
        for (int i = 0; i < wordsContainer.size(); i++) {
            trie->insert(wordsContainer[i], i);
        }
        auto n = wordsQuery.size();
        vector<int> res(n);
        for (auto i = 0; i < n; i++) {
            auto cur = trie;
            for (int j = wordsQuery[i].size() - 1; j >= 0; j--) {
                int u = wordsQuery[i][j] - 'a';
                if (!cur->son[u]) break;
                cur = cur->son[u];
            }
            res[i] = cur->index;
        }
        return res;
    }
};
