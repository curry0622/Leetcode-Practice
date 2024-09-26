class MyCalendar {
public:
    vector<vector<int>> events;
    MyCalendar() {

    }

    bool book(int start, int end) {
        bool inserted = false;
        if (events.size() == 0) {
            events.push_back({start, end});
            inserted = true;
        }
        else {
            for (int i = 0; i < events.size(); i++) {
                int s = events[i][0], e = events[i][1];
                if (end <= s) {
                    // insert
                    events.insert(events.begin() + i, {start, end});
                    inserted = true;
                    break;
                } else if (start >= e) {
                    // move on
                    continue;
                } else {
                    // failed
                    return false;
                }
            }
        }
        if (!inserted)
            events.push_back({start, end});
        return true;
    }

    void printVec(vector<vector<int>> vec) {
        for (auto v : vec) {
            cout << v[0] << ", " << v[1] << endl;
        }
        cout << endl;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */