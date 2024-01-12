
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for (char c : ransomNote) {
            int index = magazine.find(c);
            if (index == string::npos)
                return false;
            magazine.erase(index, 1);
        }
        return true;
    }
};