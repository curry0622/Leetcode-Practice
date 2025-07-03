class Solution {
public:
    char kthCharacter(int k) {
        string curr = "a";
        while (curr.size() < k) {
            string tmp = "";
            for (char c : curr) {
                if (c == 'z') tmp += 'a';
                else tmp += char(c + 1);
            }
            curr += tmp;
        }
        return curr[k-1];
    }
};