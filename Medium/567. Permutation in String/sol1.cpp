class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        vector<int> freq1 = cntFreq(s1);
        for (int i = 0; i <= s2.size()-s1.size(); i++) {
            vector<int> freq2 = cntFreq(s2.substr(i, s1.size()));
            if (freq1 == freq2)
                return true;
        }

        return false;
    }

    vector<int> cntFreq(string str) {
        vector<int> freq(26, 0);
        for (const char& c : str)
            freq[c-'a']++;
        return freq;
    }
};