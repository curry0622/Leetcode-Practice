class CustomStack {
private:
    int MAX_SIZE;
    int end = -1;
    vector<int> vec;

public:
    CustomStack(int maxSize) {
        MAX_SIZE = maxSize;
        vec = vector<int>(1000, -1);
    }

    int getSize() {
        return end + 1;
    }

    bool isEmpty() {
        return getSize() == 0;
    }

    bool isFull() {
        return getSize() == MAX_SIZE;
    }

    void push(int x) {
        if (isFull())
            return;
        vec[++end] = x;
    }

    int pop() {
        if (isEmpty())
            return -1;
        return vec[end--];
    }

    void increment(int k, int val) {
        for (int i = 0; i < k; i++) {
            vec[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */