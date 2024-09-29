#include <bits/stdc++.h>

using namespace std;

class AllOne {
    struct Node {
        int val;
        unordered_set<string> keys;
        Node *prev, *next;

        explicit Node(int v) {
            val = v;
            prev = next = nullptr;
        }

        ~Node() = default;
    };

    Node *head, *tail;
    unordered_map<string, Node *> map;

    static Node *add_to_next(Node *node, string &key, int val) {
        if (node->next->val == val) {
            node->next->keys.insert(key);
            return node->next;
        }
        auto next = node->next;
        auto new_node = new Node(val);
        new_node->keys.insert(key);
        new_node->prev = node, node->next = new_node;
        new_node->next = next, next->prev = new_node;
        return new_node;
    }

    static void delete_node(Node *node) {
        auto prev = node->prev, next = node->next;
        prev->next = next, next->prev = prev;
        delete node;
    }

public:
    AllOne() {
        head = new Node(-1), tail = new Node(-1);
        head->next = tail, tail->prev = head;
    }

    void inc(string key) {
        if (map.find(key) == map.end()) {
            map[key] = add_to_next(head, key, 1);
        } else {
            auto node = map[key];
            node->keys.erase(key);
            if (node->next->val == node->val + 1) {
                node->next->keys.insert(key);
                map[key] = node->next;
            } else {
                map[key] = add_to_next(node, key, node->val + 1);
            }
            if (node->keys.empty()) {
                delete_node(node);
            }
        }
    }

    void dec(string key) {
        auto node = map[key];
        node->keys.erase(key);
        if (node->prev->val == node->val - 1) {
            node->prev->keys.insert(key);
            map[key] = node->prev;
        } else {
            if (node->val != 1) {
                map[key] = add_to_next(node->prev, key, node->val - 1);
            } else {
                map.erase(key);
            }
        }
        if (node->keys.empty()) {
            delete_node(node);
        }
    }

    string getMaxKey() {
        if (map.empty()) return "";
        return *tail->prev->keys.begin();
    }

    string getMinKey() {
        if (map.empty()) return "";
        return *head->next->keys.begin();
    }
};