class Person {
public:
    string name;
    int height;
    Person(string n, int h) : name(n), height(h) {}
};

bool compareByHeight(const Person &a, const Person &b) {
    return a.height > b.height;
}

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<Person> people(n, Person("", 0));
        for (int i = 0; i < n; i++) {
            people[i] = Person(names[i], heights[i]);
        }
        sort(people.begin(), people.end(), compareByHeight);
        vector<string> res;
        for (auto p : people) {
            res.push_back(p.name);
        }
        return res;
    }
};