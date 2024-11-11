#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *modifiedList(vector<int> &nums, ListNode *head) {
        auto dummy = new ListNode(-1), cur = dummy;
        unordered_set<int> s(nums.begin(), nums.end());
        for (auto node = head; node;) {
            auto next = node->next;
            if (!s.contains(node->val)) {
                cur->next = node;
                node->next = nullptr;
                cur = cur->next;
            }
            node = next;
        }
        auto ans = dummy->next;
        delete dummy;
        return ans;
    }
};