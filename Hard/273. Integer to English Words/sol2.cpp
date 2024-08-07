class Solution {
public:
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";

        vector<string> units = {"", " Thousand", " Million", " Billion"};
        int index = 0;
        string res = "";
        while (num > 0) {
            int remainder = num % 1000;
            num /= 1000;
            if (remainder == 0) {
                index++;
                continue;
            }

            res = units[index] + res;
            if ((remainder % 100) <= 19) {
                res = specialNum2Words(remainder % 100) + res;
            } else {
                res = specialNum2Words((remainder % 100) / 10 * 10) + specialNum2Words((remainder % 100) % 10) + res;
            }
            if ((remainder / 100) > 0) {
                res = specialNum2Words(remainder / 100) + " Hundred" + res;
            }
            index++;
        }

        return res.substr(1, res.size()-1);
    }

    string specialNum2Words (int num) {
        switch (num) {
            case 0:
                return "";
            case 1:
                return " One";
            case 2:
                return " Two";
            case 3:
                return " Three";
            case 4:
                return " Four";
            case 5:
                return " Five";
            case 6:
                return " Six";
            case 7:
                return " Seven";
            case 8:
                return " Eight";
            case 9:
                return " Nine";
            case 10:
                return " Ten";
            case 11:
                return " Eleven";
            case 12:
                return " Twelve";
            case 13:
                return " Thirteen";
            case 14:
                return " Fourteen";
            case 15:
                return " Fifteen";
            case 16:
                return " Sixteen";
            case 17:
                return " Seventeen";
            case 18:
                return " Eighteen";
            case 19:
                return " Nineteen";
            case 20:
                return " Twenty";
            case 30:
                return " Thirty";
            case 40:
                return " Forty";
            case 50:
                return " Fifty";
            case 60:
                return " Sixty";
            case 70:
                return " Seventy";
            case 80:
                return " Eighty";
            case 90:
                return " Ninety";
        }
        return "";
    }
};