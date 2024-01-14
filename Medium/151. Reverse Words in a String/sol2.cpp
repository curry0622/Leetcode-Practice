class Solution {
public:
    string reverseWords(string str) {
        stringstream ss(str);
        string token;
        vector<string> vec;

        while(ss >> token) {
            vec.push_back(token);
        }
        reverse(vec.begin(), vec.end());

        string res = "";
        for (string s : vec)
            res += s + " ";
        res.pop_back();

        return res;
    }
};