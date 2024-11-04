class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int cnt = 1;
        char curr = word[0];
        for (int i = 1; i < word.size(); i++) {
            if (word[i] == curr && cnt < 9) {
                cnt++;
            } else {
                comp += to_string(cnt) + curr;
                cnt = 1;
                curr = word[i];
            }
        }
        comp += to_string(cnt) + curr;
        return comp;
    }
};