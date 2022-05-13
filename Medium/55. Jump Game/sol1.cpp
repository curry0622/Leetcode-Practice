class Solution {
public:
    bool canJump(vector<int>& nums) {
        int minJumps = 0;
        for(int i = nums.size() - 2; i >= 0; i--) {
            minJumps++;
            if(nums[i] >= minJumps)
                minJumps = 0;
        }
        return minJumps == 0;
    }
    // My version (TLE):
    // bool canJump(vector<int>& nums) {
    //     vector<bool> canJumpVec(nums.size(), false);
    //     canJumpVec[0] = true;
    //     for(int i = 0; i < canJumpVec.size(); i++) {
    //         if(canJumpVec[i]) {
    //             int steps = nums[i];
    //             for(int j = 1; j <= steps; j++) {
    //                 if(i + j < canJumpVec.size())
    //                     canJumpVec[i + j] = true;
    //                 if(canJumpVec.back())
    //                     return true;
    //             }
    //         }
    //     }
    //     return canJumpVec.back();
    // }
};
