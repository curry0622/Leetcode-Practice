class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size())
            return false;
        int len = word1.size();
        int cnt1[26] = {0};
        int cnt2[26] = {0};
        for (int i = 0; i < len; i++) {
            cnt1[word1[i]-'a']++;
            cnt2[word2[i]-'a']++;
        }

        set<int> st1, st2;
        map<int, int> record1, record2;
        for (int i = 0; i < 26; i++) {
            if (cnt1[i] > 0)
                st1.insert(i);
            if (cnt2[i] > 0)
                st2.insert(i);
            record1[cnt1[i]]++;
            record2[cnt2[i]]++;
        }
        if (st1.size() != st2.size() || record1.size() != record2.size())
            return false;

        for (
            auto iter1 = st1.begin(), iter2 = st2.begin();
            iter1 != st1.end() && iter2 != st2.end();
            iter1++, iter2++
        ) {
            if (*iter1 != *iter2)
                return false;
        }

        for (
            auto iter1 = record1.begin(), iter2 = record2.begin();
            iter1 != record1.end() && iter2 != record2.end();
            iter1++, iter2++
        ) {
            if (iter1->first != iter2->first || iter1->second != iter2->second)
                return false;
        }

        return true;
    }
};