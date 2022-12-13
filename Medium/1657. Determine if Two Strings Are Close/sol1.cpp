class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        if(len1 != len2)
            return false;
        else if(len1 == 1)
            return word1 == word2;

        vector<int> cnt1 = vector<int>(26, 0);
        vector<int> cnt2 = cnt1;

        for(int i = 0; i < len1; i++)
            cnt1[word1[i] - 'a']++;
        for(int i = 0; i < len2; i++)
            cnt2[word2[i] - 'a']++;

        for(int i = 0; i < 26; i++)
            if((cnt1[i] > 0 && cnt2[i] == 0) || cnt2[i] > 0 && cnt1[i] == 0)
                return false;

        sort(cnt1.begin(), cnt1.end());
        sort(cnt2.begin(), cnt2.end());

        for(int i = 0; i < 26; i++)
            if(cnt1[i] != cnt2[i])
                return false;
        return true;
    }
};