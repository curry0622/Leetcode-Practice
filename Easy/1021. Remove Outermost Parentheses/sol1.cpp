class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> record;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                if(record.size() == 0) {
                    s.erase(i, 1);
                    i--;
                }
                record.push('(');
            } else {
                record.pop();
                if(record.size() == 0) {
                    s.erase(i, 1);
                    i--;
                }
            }
        }
        return s;
    }
};