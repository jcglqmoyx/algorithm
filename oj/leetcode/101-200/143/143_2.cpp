struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {
    }

    explicit ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode* next) : val(x), next(next) {
    }
};

class Solution {
public:
    static void reorderList(ListNode* head) {
        auto slow = head, fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next, fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        ListNode *prev = nullptr, *cur = fast;
        while (cur) {
            const auto next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        fast = prev;
        slow = head;
        while (fast) {
            const auto slow_next = slow->next;
            slow->next = fast;
            slow = slow_next;
            const auto fast_next = fast->next;
            fast->next = slow;
            fast = fast_next;
        }
    }
};
