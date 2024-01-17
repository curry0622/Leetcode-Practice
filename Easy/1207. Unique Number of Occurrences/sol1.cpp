class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        unordered_set<int> s;
        for (int n : arr)
            freq[n]++;
        for (auto iter = freq.begin(); iter != freq.end(); iter++) {
            if (s.find(iter->second) != s.end())
                return false;
            s.insert(iter->second);
        }
        return true;
    }
};