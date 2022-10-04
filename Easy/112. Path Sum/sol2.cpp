/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, const int& targetSum, int currSum = 0, bool first = true) {
        if(!root)
            return targetSum == currSum && !first;
        if(root -> left && root -> right)
            return hasPathSum(root -> left, targetSum, currSum + root -> val, false)
                || hasPathSum(root -> right, targetSum, currSum + root -> val, false);
        if(root -> left)
            return hasPathSum(root -> left, targetSum, currSum + root -> val, false);
        return hasPathSum(root -> right, targetSum, currSum + root -> val, false);
    }
};