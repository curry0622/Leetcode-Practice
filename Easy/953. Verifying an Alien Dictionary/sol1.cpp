class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> index;
        for (int i = 0; i < order.size(); i++) {
            index[order[i]] = i;
        }
        for (int i = 1; i < words.size(); i++) {
            string prev = words[i-1];
            string curr = words[i];
            int j = 0, k = 0;
            bool sorted = false;
            while (j < prev.size() && k < curr.size()) {
                int prev_idx = index[prev[j]];
                int curr_idx = index[curr[k]];
                if (prev_idx == curr_idx) {
                    j++, k++;
                } else if (prev_idx < curr_idx) {
                    sorted = true;
                    break;
                } else {
                    return false;
                }
            }
            if (!sorted) {
                if (j == prev.size() && k == curr.size())
                    continue;
                if (k < curr.size())
                    continue;
                if (j < prev.size())
                    return false;
            }
        }
        return true;
    }
};