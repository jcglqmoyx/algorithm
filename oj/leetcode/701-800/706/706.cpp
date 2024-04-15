#include <bits/stdc++.h>

using namespace std;

class MyHashMap {
    static constexpr int N = 997;
    int h[N], w[10000], e[10000], ne[10000], idx;
public:
    MyHashMap() {
        memset(h, -1, sizeof h);
        idx = 0;
    }

    void put(int key, int value) {
        int u = key % N;
        bool found = false;
        for (int i = h[u]; ~i; i = ne[i]) {
            if (e[i] == key) {
                w[i] = value;
                found = true;
                break;
            }
        }
        if (!found) {
            e[idx] = key, w[idx] = value, ne[idx] = h[u], h[u] = idx++;
        }
    }

    int get(int key) {
        int u = key % N;
        for (int i = h[u]; ~i; i = ne[i]) {
            if (e[i] == key) {
                return w[i];
            }
        }
        return -1;
    }

    void remove(int key) {
        int u = key % N;
        for (int prev = -1, i = h[u]; ~i; i = ne[i]) {
            if (e[i] == key) {
                if (i == h[u]) {
                    h[u] = ne[i];
                } else {
                    ne[prev] = ne[i];
                }
            }
            prev = i;
        }
    }
};