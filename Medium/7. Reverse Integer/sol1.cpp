class Solution {
public:
    int reverse(int x) {
        string xStr = to_string(x), ansStr;
        ::reverse(xStr.begin(), xStr.end());
        for(int i = 0; i < xStr.length(); i++) {
            if(xStr[i] == '-')
                ansStr = "-" + ansStr;
            else
                ansStr.push_back(xStr[i]);
        }
        try {
            return stoi(ansStr);
        } catch(...) {
            return 0;
        }
    }
};