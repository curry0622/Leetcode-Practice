class Solution {
public:
    vector<int> record;

    int numDecodings(string s) {
        record = vector<int>(s.size() + 1, -1);
        return decode(s, 0);
    }

    int decode(const string& s, int idx) {
        if(record[idx] != -1)
            return record[idx];
        if(s[idx] == '0')
            record[idx] = 0;
        else if(idx == s.size())
            record[idx] = 1;
        else if(idx < s.size() - 1 && 10 * (s[idx] - '0') + (s[idx + 1] - '0') <= 26)
            record[idx] = decode(s, idx + 1) + decode(s, idx + 2);
        else
            record[idx] = decode(s, idx + 1);
        return record[idx];
    }
};