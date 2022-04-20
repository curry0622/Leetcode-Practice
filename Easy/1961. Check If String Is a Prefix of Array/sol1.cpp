class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int sumIdx = 0;    
        for(int i = 0; i < words.size(); i++) {
            string cut, ss = words[i];
            if(i == 0) {
                cut = s.substr(0, ss.length());
            } else {
                sumIdx += words[i - 1].length();
                cut = s.substr(sumIdx, ss.length());
            }
            cout << cut << " " << ss << endl;
            if(cut.compare("") == 0) {
                return true;
            }
            if(cut.compare(ss) != 0) {
                return false;
            }
            if(i == words.size() - 1) {
                sumIdx += words[i].length();
                if(sumIdx < s.length()) {
                    return false;
                } else {
                    return true;
                }
            }
        }
        return false;
    }
};