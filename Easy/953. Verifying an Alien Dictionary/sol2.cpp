class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, char> transform;
        int i = 0;
        for (const char& c : order) {
            transform[c] = char('a' + i++);
        }
        for (string& word : words) {
            for (char& c : word) {
                c = transform[c];
            }
        }
        return is_sorted(words.begin(), words.end());
    }
};