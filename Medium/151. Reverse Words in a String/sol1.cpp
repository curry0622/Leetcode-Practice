class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word = "";
        bool start = false;
        for (char c : s) {
            if (c != ' ' && !start) {
                start = true;
                word = c;
            } else if (c != ' ') {
                word += c;
            } else if (word.size() > 0) {
                words.push_back(word);
                word = "";
            }
        }
        if (word.size() > 0)
            words.push_back(word);
        string res = "";
        for (string word : words) {
            res = word + " " + res;
        }
        res.pop_back();
        return res;
    }
};