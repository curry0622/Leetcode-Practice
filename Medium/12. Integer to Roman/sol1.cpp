class Solution {
public:
    string intToRoman(int num) {
        string s;
        while (num != 0) {
            if (num >= 1000) {
                s.push_back('M');
                num -= 1000;
            } else if (num >= 900) {
                s.push_back('C');
                s.push_back('M');
                num -= 900;
            } else if (num >= 500) {
                s.push_back('D');
                num -= 500;
            } else if (num >= 400) {
                s.push_back('C');
                s.push_back('D');
                num -= 400;
            } else if (num >= 100) {
                s.push_back('C');
                num -= 100;
            } else if (num >= 90) {
                s.push_back('X');
                s.push_back('C');
                num -= 90;
            } else if (num >= 50) {
                s.push_back('L');
                num -= 50;
            } else if (num >= 40) {
                s.push_back('X');
                s.push_back('L');
                num -= 40;
            } else if (num >= 10) {
                s.push_back('X');
                num -= 10;
            } else if (num >= 9) {
                s.push_back('I');
                s.push_back('X');
                num -= 9;
            } else if (num >= 5) {
                s.push_back('V');
                num -= 5;
            } else if (num >= 4) {
                s.push_back('I');
                s.push_back('V');
                num -= 4;
            } else if (num >= 1) {
                s.push_back('I');
                num -= 1;
            } else {
                num -= 0;
            }
        }
        return s;
    }
};