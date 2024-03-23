#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode* next) : val(x), next(next) {
    }
};

class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode *> v;
        for (auto cur = head; cur; cur = cur->next) {
            v.push_back(cur);
        }
        int i = 0, j = (int)v.size() - 1;
        for (; i + 1 < j; j--) {
            v[i]->next = v[j];
            v[j]->next = v[++i];
        }
        if (v.size() & 1) v[i]->next = nullptr;
        v[j]->next = nullptr;
    }
};
