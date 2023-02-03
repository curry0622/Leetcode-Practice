class Solution {
public:
    string convert(string s, int numRows) {
        string ans = "";
        string row[numRows];
        int r = 0;
        bool rev = false;
        for (const char& c : s) {
            row[r] += c;

            if (r == numRows - 1)
                rev = true;
            else if (r == 0)
                rev = false;

            if (!rev)
                r++;
            else
                r--;

            if (numRows == 1)
                r = 0;
        }
        for (int i = 0; i < numRows; i++)
            ans += row[i];
        return ans;
    }
};