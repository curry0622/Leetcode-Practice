class MyCircularDeque {
private:
    int maxSize;
    vector<int> v;

public:
    MyCircularDeque(int k) {
        maxSize = k;
    }

    bool insertFront(int value) {
        if (isFull())
            return false;
        v.insert(v.begin(), value);
        return true;
    }

    bool insertLast(int value) {
        if (isFull())
            return false;
        v.push_back(value);
        return true;
    }

    bool deleteFront() {
        if (isEmpty())
            return false;
        v.erase(v.begin());
        return true;
    }

    bool deleteLast() {
        if (isEmpty())
            return false;
        v.pop_back();
        return true;
    }

    int getFront() {
        if (isEmpty())
            return -1;
        return v[0];
    }

    int getRear() {
        if (isEmpty())
            return -1;
        return v.back();
    }

    bool isEmpty() {
        return v.size() == 0;
    }

    bool isFull() {
        return v.size() == maxSize;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */