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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        return dfs(root, targetSum, 0);
    }

    bool dfs(TreeNode *root, int targetSum, int currSum) {
        currSum += root -> val;
        if(!root -> left && !root -> right)
            return targetSum == currSum;
        if(!root -> left && root -> right)
            return dfs(root -> right, targetSum, currSum);
        if(root -> left && !root -> right)
            return dfs(root -> left, targetSum, currSum);
        return dfs(root -> left, targetSum, currSum)
            || dfs(root -> right, targetSum, currSum);
    }
};