class NumberContainers {
using min_heap = priority_queue<int, vector<int>, greater<int>>;
private:
    unordered_map<int, int> i2n;
    unordered_map<int, min_heap> n2i;

public:
    NumberContainers() {

    }

    void change(int index, int number) {
        i2n[index] = number;
        n2i[number].push(index);
    }

    int find(int number) {
        while (!n2i[number].empty()) {
            int i = n2i[number].top();
            if (i2n[i] != number) {
                n2i[number].pop();
            } else {
                return i;
            }
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */