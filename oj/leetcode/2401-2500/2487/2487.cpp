struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    ListNode *reverse(ListNode *node) {
        ListNode *prev = nullptr;
        while (node) {
            auto ne = node->next;
            node->next = prev;
            prev = node;
            node = ne;
        }
        return prev;
    }

public:
    ListNode *removeNodes(ListNode *head) {
        head = reverse(head);
        auto res = head;
        while (head) {
            auto p = head->next;
            while (p && head->val > p->val) p = p->next;
            head->next = p;
            head = head->next;
        }
        return reverse(res);
    }
};