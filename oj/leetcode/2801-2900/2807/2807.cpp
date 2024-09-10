struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int gcd(int x, int y) {
    return x % y == 0 ? y : gcd(y, x % y);
}

class Solution {
public:
    ListNode *insertGreatestCommonDivisors(ListNode *head) {
        auto res = head;
        while (head) {
            if (!head->next) break;
            auto ne = head->next;
            auto node = new ListNode(gcd(head->val, head->next->val));
            head->next = node;
            node->next = ne;
            head = ne;
        }
        return res;
    }
};