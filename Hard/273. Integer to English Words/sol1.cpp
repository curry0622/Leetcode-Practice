class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        vector<string> ans, tmp;
        if (num / 1000000000 > 0) {
            ans.push_back(oneDigitToWord(num / 1000000000));
            ans.push_back("Billion");
            num %= 1000000000;
            if (num == 0) return insertSpaces(ans);
        }
        if (num / 1000000 > 0) {
            if ((num / 1000000) / 100 > 0) {
                tmp = threeDigitToWord((num / 1000000));
                ans.insert(ans.end(), tmp.begin(), tmp.end());
            } else if ((num / 1000000) / 10 > 0) {
                tmp = twoDigitToWord((num / 1000000));
                ans.insert(ans.end(), tmp.begin(), tmp.end());
            } else {
                ans.push_back(oneDigitToWord(num / 1000000));
            }
            ans.push_back("Million");
            num %= 1000000;
            if (num == 0) return insertSpaces(ans);
        }
        if (num / 1000 > 0) {
            if ((num / 1000) / 100 > 0) {
                tmp = threeDigitToWord(num / 1000);
                ans.insert(ans.end(), tmp.begin(), tmp.end());
            } else if ((num / 1000) / 10 > 0) {
                tmp = twoDigitToWord(num / 1000);
                ans.insert(ans.end(), tmp.begin(), tmp.end());
            } else {
                ans.push_back(oneDigitToWord(num / 1000));
            }
            ans.push_back("Thousand");
            num %= 1000;
            if (num == 0) return insertSpaces(ans);
        }
        if (num / 100 > 0) {
            tmp = threeDigitToWord(num);
            ans.insert(ans.end(), tmp.begin(), tmp.end());
        } else if (num / 10 > 0) {
            tmp = twoDigitToWord(num);
            ans.insert(ans.end(), tmp.begin(), tmp.end());
        } else {
            ans.push_back(oneDigitToWord(num));
        }
        return insertSpaces(ans);
    }

    vector<string> threeDigitToWord(int num) {
        int hundsDigit = num / 100;
        vector<string> ans;
        switch(hundsDigit) {
            case 1:
                ans.push_back("One");
                break;
            case 2:
                ans.push_back("Two");
                break;
            case 3:
                ans.push_back("Three");
                break;
            case 4:
                ans.push_back("Four");
                break;
            case 5:
                ans.push_back("Five");
                break;
            case 6:
                ans.push_back("Six");
                break;
            case 7:
                ans.push_back("Seven");
                break;
            case 8:
                ans.push_back("Eight");
                break;
            case 9:
                ans.push_back("Nine");
                break;
        }
        ans.push_back("Hundred");
        vector<string> twoVec = twoDigitToWord(num % 100);
        ans.insert(ans.end(), twoVec.begin(), twoVec.end());
        return ans;
    }

    vector<string> twoDigitToWord(int num) {
        int tensDigit = num / 10;
        int unitsDigit = num % 10;
        vector<string> ans;
        if (tensDigit == 1) {
            switch(num) {
                case 10:
                    ans.push_back("Ten");
                    return ans;
                case 11:
                    ans.push_back("Eleven");
                    return ans;
                case 12:
                    ans.push_back("Twelve");
                    return ans;
                case 13:
                    ans.push_back("Thirteen");
                    return ans;
                case 14:
                    ans.push_back("Fourteen");
                    return ans;
                case 15:
                    ans.push_back("Fifteen");
                    return ans;
                case 16:
                    ans.push_back("Sixteen");
                    return ans;
                case 17:
                    ans.push_back("Seventeen");
                    return ans;
                case 18:
                    ans.push_back("Eighteen");
                    return ans;
                case 19:
                    ans.push_back("Nineteen");
                    return ans;
            }
        }
        switch(tensDigit) {
            case 2:
                ans.push_back("Twenty");
                break;
            case 3:
                ans.push_back("Thirty");
                break;
            case 4:
                ans.push_back("Forty");
                break;
            case 5:
                ans.push_back("Fifty");
                break;
            case 6:
                ans.push_back("Sixty");
                break;
            case 7:
                ans.push_back("Seventy");
                break;
            case 8:
                ans.push_back("Eighty");
                break;
            case 9:
                ans.push_back("Ninety");
                break;
        }
        if (unitsDigit != 0) {
            ans.push_back(oneDigitToWord(unitsDigit));
        }
        return ans;
    }

    string oneDigitToWord(int num) {
        switch(num) {
            case 1:
                return "One";
            case 2:
                return "Two";
            case 3:
                return "Three";
            case 4:
                return "Four";
            case 5:
                return "Five";
            case 6:
                return "Six";
            case 7:
                return "Seven";
            case 8:
                return "Eight";
            case 9:
                return "Nine";
        }
        return "";
    }

    string insertSpaces(vector<string> vec) {
        string ans = "";
        for(int i = 0; i < vec.size() - 1; i++) {
            ans += vec.at(i);
            ans += " ";
        }
        ans += vec.back();
        return ans;
    }
};