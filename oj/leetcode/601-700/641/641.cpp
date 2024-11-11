class MyCircularDeque {
    int q[2001], capacity, hh, tt;
public:
    MyCircularDeque(int k) {
        this->capacity = k;
        this->hh = 1000;
        this->tt = 999;
    }

    bool insertFront(int value) {
        if (tt - hh + 1 == capacity) return false;
        q[--hh] = value;
        return true;
    }

    bool insertLast(int value) {
        if (tt - hh + 1 == capacity) return false;
        q[++tt] = value;
        return true;
    }

    bool deleteFront() {
        if (tt - hh + 1 == 0) return false;
        hh++;
        return true;
    }

    bool deleteLast() {
        if (tt - hh + 1 == 0) return false;
        tt--;
        return true;
    }

    int getFront() {
        return tt - hh + 1 ? q[hh] : -1;
    }

    int getRear() {
        return tt - hh + 1 ? q[tt] : -1;
    }

    bool isEmpty() {
        return tt - hh + 1 == 0;
    }

    bool isFull() {
        return tt - hh + 1 == capacity;
    }
};