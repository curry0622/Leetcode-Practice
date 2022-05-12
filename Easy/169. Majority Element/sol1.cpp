class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0;
        int max = 0;
        map<int, int> cnt;
        for(auto num: nums) {
            if(cnt.find(num) == cnt.end()) {
                cnt[num] = 1;
            } else {
                cnt[num]++;
            }
            if(max < cnt[num]) {
                max = cnt[num];
                ans = num;
            }
        }
        return ans;
    }
};