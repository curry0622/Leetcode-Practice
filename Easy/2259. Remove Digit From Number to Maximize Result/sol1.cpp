class Solution {
public:
    string removeDigit(string number, char digit) {
        vector<string> removed;
        for(int i = 0; i < number.size(); i++) {
            if(number[i] == digit) {
                string tmp = number;
                tmp.erase(i, 1);
                removed.push_back(tmp);
            }
        }
        sort(removed.begin(), removed.end());
        return removed.back();
    }
};