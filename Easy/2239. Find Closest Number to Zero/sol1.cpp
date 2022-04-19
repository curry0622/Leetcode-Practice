class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans = 0;
        int min = 100000;
        for(int i = 0; i < nums.size(); i++) {
            int num = nums.at(i);
            int anum = abs(num);
            if(min > anum) {
                min = anum;
                ans = num;
            } else if(min == anum && ans < anum) {
                ans = num;
            }
        }
        return ans;
    }
};