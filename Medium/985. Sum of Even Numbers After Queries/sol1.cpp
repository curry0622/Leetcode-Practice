class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = nums.size(), q = queries.size();
        int evenSum = 0;

        for(int i = 0; i < q; i++) {
            int val = queries[i][0];
            int idx = queries[i][1];

            if(i == 0) {
                nums[idx] += val;
                for(int j = 0; j < n; j++) {
                    if(nums[j] % 2 == 0) {
                        evenSum += nums[j];
                    }
                }
            } else {
                if(nums[idx] % 2 == 0) {
                    // in
                    if(val % 2 == 0) {
                        evenSum += val;
                    } else {
                        evenSum -= nums[idx];
                    }
                } else {
                    // not in
                    if(val % 2 != 0) {
                        evenSum += nums[idx] + val;
                    }
                }
                nums[idx] += val;
            }

            ans.push_back(evenSum);
        }

        return ans;
    }
};