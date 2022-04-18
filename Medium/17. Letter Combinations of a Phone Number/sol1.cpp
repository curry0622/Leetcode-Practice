class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int len = digits.length();
        if (len == 1) {
            string letters = digitLetters(digits[0]);
            for(int i = 0; i < letters.length(); i++) {
                string s(1, letters[i]);
                ans.push_back(s);
            }
        }
        if (len == 2) {
            string letters0 = digitLetters(digits[0]);
            string letters1 = digitLetters(digits[1]);
            for(int i = 0; i < letters0.length(); i++) {
                for(int j = 0; j < letters1.length(); j++) {
                    string s;
                    s.push_back(letters0[i]);
                    s.push_back(letters1[j]);
                    ans.push_back(s);
                }
            }
        }
        if (len == 3) {
            string letters0 = digitLetters(digits[0]);
            string letters1 = digitLetters(digits[1]);
            string letters2 = digitLetters(digits[2]);
            for(int i = 0; i < letters0.length(); i++) {
                for(int j = 0; j < letters1.length(); j++) {
                    for(int k = 0; k < letters2.length(); k++) {
                        string s;
                        s.push_back(letters0[i]);
                        s.push_back(letters1[j]);
                        s.push_back(letters2[k]);
                        ans.push_back(s);
                    }
                }
            }
        }
        if (len == 4) {
            string letters0 = digitLetters(digits[0]);
            string letters1 = digitLetters(digits[1]);
            string letters2 = digitLetters(digits[2]);
            string letters3 = digitLetters(digits[3]);
            for(int i = 0; i < letters0.length(); i++) {
                for(int j = 0; j < letters1.length(); j++) {
                    for(int k = 0; k < letters2.length(); k++) {
                        for(int l = 0; l < letters3.length(); l++) {
                            string s;
                            s.push_back(letters0[i]);
                            s.push_back(letters1[j]);
                            s.push_back(letters2[k]);
                            s.push_back(letters3[l]);
                            ans.push_back(s);
                        }
                    }
                }
            }
        }
        return ans;
    }

    string digitLetters(char d) {
        switch(d - '0') {
            case 2:
                return "abc";
            case 3:
                return "def";
            case 4:
                return "ghi";
            case 5:
                return "jkl";
            case 6:
                return "mno";
            case 7:
                return "pqrs";
            case 8:
                return "tuv";
            case 9:
                return "wxyz";
        }
        return "";
    }
};