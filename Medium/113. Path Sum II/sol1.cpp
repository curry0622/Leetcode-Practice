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
    vector<vector<int>> ans;

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return ans;
        vector<int> record;
        dfs(root, targetSum, 0, record);
        return ans;
    }

    void dfs(TreeNode *root, int targetSum, int currSum, vector<int> record) {
        currSum += root -> val;
        record.push_back(root -> val);
        if(!root -> left && !root -> right) {
            if(targetSum == currSum) {
                ans.push_back(record);
            }
        }
        if(root -> left) {
            dfs(root -> left, targetSum, currSum, record);
        }
        if(root -> right) {
            dfs(root -> right, targetSum, currSum, record);
        }
    }
};