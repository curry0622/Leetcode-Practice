class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        for(int i = 0; i < pow(2, nums.size()); i++) {
            int j = 0, num = i;
            vector<int> tmp;
            while(num != 0) {
                if(num & 1 == 1)
                    tmp.push_back(nums[j]);
                num = num >> 1;
                j++;
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};