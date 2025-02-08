class NumberContainers {
private:
    unordered_map<int,int> i2n;
    unordered_map<int,set<int>> n2i;

public:
    NumberContainers() {

    }

    void change(int index, int number) {
        int old = i2n[index];
        if (old != 0) {
            n2i[old].erase(index);
        }
        i2n[index] = number;
        n2i[number].insert(index);
    }

    int find(int number) {
        if (n2i[number].size() > 0) {
            return *n2i[number].begin();
        }
        return -1;
    }

    void print(int number) {
        auto indices = n2i[number];
        cout << number << ": ";
        for (auto i : indices) {
            cout << i << ", ";
        }
        cout << endl;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */