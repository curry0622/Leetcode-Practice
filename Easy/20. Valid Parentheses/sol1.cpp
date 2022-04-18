class Solution {
public:
    bool isValid(string s) {
        vector<char> inputs;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                inputs.push_back(s[i]);
            } else if (inputs.size() == 0) {
                return false;
            }
            if (s[i] == ')') {
                if (inputs.back() == '(')
                    inputs.pop_back();
                else
                    return false;
            }
            if (s[i] == ']') {
                if (inputs.back() == '[')
                    inputs.pop_back();
                else
                    return false;
            }
            if (s[i] == '}') {
                if (inputs.back() == '{')
                    inputs.pop_back();
                else
                    return false;
            }
        }
        return inputs.size() == 0;
    }
};