#include <bits/stdc++.h>

using namespace std;

class MyHashSet {
    static constexpr int N = 997;
    int h[N], e[10000], ne[10000], idx;
public:
    MyHashSet() {
        memset(h, -1, sizeof h);
        idx = 0;
    }

    void add(int key) {
        int u = key % N;
        for (int i = h[u]; ~i; i = ne[i]) {
            if (e[i] == key) return;
        }
        e[idx] = key, ne[idx] = h[u], h[u] = idx++;
    }

    void remove(int key) {
        int u = key % N;
        for (int i = h[u], prev = -1; ~i; i = ne[i]) {
            if (e[i] == key) {
                if (i == h[u]) h[u] = ne[i];
                else ne[prev] = ne[i];
                break;
            }
            prev = i;
        }
    }

    bool contains(int key) {
        int u = key % N;
        for (int i = h[u]; ~i; i = ne[i]) {
            if (e[i] == key) {
                return true;
            }
        }
        return false;
    }
};