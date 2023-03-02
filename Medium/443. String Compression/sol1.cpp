class Solution {
public:
    int compress(vector<char>& chars) {
        for (int i = 0; i < chars.size(); i++) {
            int cnt = 1;
            char c = chars[i];
            for (int j = i+1; j < chars.size(); j++) {
                if (chars[j] == c) {
                    cnt++;
                } else {
                    break;
                }
            }
            chars.erase(chars.begin()+i+1, chars.begin()+i+cnt);
            if (cnt > 1) {
                vector<char> cntVec = decToChars(cnt);
                chars.insert(chars.begin()+i+1, cntVec.begin(), cntVec.end());
                i += cntVec.size();
            }
        }
        return chars.size();
    }

    vector<char> decToChars(int num) {
        vector<char> res;
        while (num > 0) {
            res.push_back(char('0' + num % 10));
            num /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};