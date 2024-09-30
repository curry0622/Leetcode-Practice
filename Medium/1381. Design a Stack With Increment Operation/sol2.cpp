class CustomStack {
public:
    vector<int> stk, inc;
    int MAX_SIZE;

    CustomStack(int maxSize) {
        MAX_SIZE = maxSize;
    }

    void push(int x) {
        if (stk.size() >= MAX_SIZE) return;
        stk.push_back(x);
        inc.push_back(0);
    }

    int pop() {
        if (stk.size() == 0) return -1;
        int res = stk.back() + inc.back();
        if (inc.size() >= 2) {
            inc[inc.size()-2] += inc.back();
        }
        stk.pop_back();
        inc.pop_back();
        return res;
    }

    void increment(int k, int val) {
        if (inc.size() == 0)
            return;
        if (inc.size() < k)
            inc.back() += val;
        else
            inc[k-1] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */