class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0, cnt = 0;
        unordered_map<string, int> record;

        for(auto& w : words) {
            string rw = w;
            reverse(rw.begin(), rw.end());

            if(w == rw)
                cnt++;

            if(record.find(rw) != record.end()) {
                if(record[rw] > 0) {
                    ans += 4;
                    record[rw]--;
                    if(w == rw)
                        cnt -= 2;
                } else if(record.find(w) != record.end()) {
                    record[w]++;
                } else {
                    record[w] = 1;
                }
            } else if(record.find(w) != record.end()) {
                record[w]++;
            } else {
                record[w] = 1;
            }
        }

        return cnt > 0 ? ans + 2 : ans;
    }
};