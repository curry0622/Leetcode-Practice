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
    int maxAncestorDiff(TreeNode* root) {
        int res = 0;
        dfs(root, res, root->val, root->val);
        return res;
    }

    void dfs(TreeNode* root, int& res, int maxAncestorVal, int minAncestorVal) {
        if (!root)
            return;
        res = max(res, abs(root->val - maxAncestorVal));
        res = max(res, abs(root->val - minAncestorVal));
        maxAncestorVal = max(maxAncestorVal, root->val);
        minAncestorVal = min(minAncestorVal, root->val);
        dfs(root->left, res, maxAncestorVal, minAncestorVal);
        dfs(root->right, res, maxAncestorVal, minAncestorVal);
    }
};