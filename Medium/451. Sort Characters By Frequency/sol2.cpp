struct CustomCompare {
    bool operator()(const int& a, const int& b) const {
        return a > b;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(62, 0); // 0~9, A~Z, a~z
        for (const char& c : s) {
            if (c - 'a' >= 0) {
                freq[36 + c - 'a']++;
            } else if (c - 'A' >= 0) {
                freq[10 + c - 'A']++;
            } else {
                freq[c - '0']++;
            }
        }

        map<int, vector<char>, CustomCompare> mp;
        for (int i = 0; i < 10; i++) {
            mp[freq[i]].push_back(char('0' + i));
        }
        for (int i = 10; i < 36; i++) {
            mp[freq[i]].push_back(char('A' + i - 10));
        }
        for (int i = 36; i < 62; i++) {
            mp[freq[i]].push_back(char('a' + i - 26 - 10));
        }

        string res;
        for (auto iter = mp.begin(); iter != mp.end(); iter++) {
            for (const char& c : iter->second) {
                for (int i = 0; i < iter->first; i++) {
                    res += c;
                }
            }
        }

        return res;
    }
};