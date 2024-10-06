class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if (s1 == s2)
            return true;

        vector<string> v1, v2;
        std::istringstream ss1(s1), ss2(s2);
        std::string word;

        while (ss1 >> word) {
            v1.push_back(word);
        }
        while (ss2 >> word) {
            v2.push_back(word);
        }

        vector<string> prefix, suffix;
        for (int i = 0; i < min(v1.size(), v2.size()); i++) {
            if (v1[i] == v2[i]) {
                prefix.push_back(v1[i]);
            } else {
                break;
            }
        }
        for (int i1 = v1.size() - 1, i2 = v2.size() - 1; i1 >= 0 && i2 >= 0; i1--, i2--) {
            if (v1[i1] == v2[i2]) {
                suffix.push_back(v1[i1]);
            } else {
                break;
            }
        }
        reverse(suffix.begin(), suffix.end());

        if (prefix == v1 || prefix == v2 || suffix == v1 || suffix == v2)
            return true;

        int i = prefix.size()-1, j = min(v1.size(), v2.size())-suffix.size();
        if (i >= j || j-i == 1)
                return true;
        return false;
    }
};