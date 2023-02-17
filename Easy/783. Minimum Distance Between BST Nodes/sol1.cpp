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
    int prev = INT_MIN;
    int minDiff = INT_MAX;

    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return minDiff;
    }

    void inorder(TreeNode* root) {
        if (!root)
            return;
        inorder(root->left);
        if (prev != INT_MIN)
            minDiff = min(minDiff, abs(prev - root->val));
        prev = root->val;
        inorder(root->right);
    }
};