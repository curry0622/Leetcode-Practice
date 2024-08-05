class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> freq;
        for (string str : arr) {
            if (freq.find(str) == freq.end()) {
                freq[str] = 1;
            } else {
                freq[str]++;
            }
        }
        string res = "";
        for (int i = 0; i < arr.size(); i++) {
            if (freq[arr[i]] == 1) {
                k--;
            }
            if (k == 0) {
                res = arr[i];
                break;
            }
        }
        return res;
    }
};