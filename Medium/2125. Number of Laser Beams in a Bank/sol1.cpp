class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int totalNum = 0;
        int lastNum = 0;
        for (const string& row : bank) {
            int num = numDevices(row);
            totalNum += lastNum * num;
            if (num != 0)
                lastNum = num;
        }
        return totalNum;
    }

    int numDevices(const string& row) {
        int num = 0;
        for (const char& c : row) {
            if (c == '1')
                num++;
        }
        return num;
    }
};