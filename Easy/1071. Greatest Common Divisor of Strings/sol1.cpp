class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string gcd = "";
        int len1 = str1.size(), len2 = str2.size();

        if (len1 > len2) {
            for (int i = len2; i > 0; i--) {
                string sub = str2.substr(0, i);
                int slen = sub.size();

                if (len1 % slen == 0 && len2 % slen == 0) {
                    string tmp1, tmp2;
                    for (int j = 0; j < len1/slen; j++)
                        tmp1 += sub;
                    for (int j = 0; j < len2/slen; j++)
                        tmp2 += sub;
                    if (tmp1 == str1 && tmp2 == str2) {
                        gcd = sub;
                        break;
                    }
                }
            }
        } else {
            for (int i = len1; i > 0; i--) {
                string sub = str1.substr(0, i);
                int slen = sub.size();

                if (len1 % slen == 0 && len2 % slen == 0) {
                    string tmp1, tmp2;
                    for (int j = 0; j < len1/slen; j++)
                        tmp1 += sub;
                    for (int j = 0; j < len2/slen; j++)
                        tmp2 += sub;
                    if (tmp1 == str1 && tmp2 == str2) {
                        gcd = sub;
                        break;
                    }
                }
            }
        }

        return gcd;
    }
};