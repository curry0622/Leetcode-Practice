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
    int minDiff = INT_MAX;
    int prev = -1;

    int minDiffInBST(TreeNode* root) {
        if (root->left != nullptr)
            minDiffInBST(root->left);

        if (prev >= 0)
            minDiff = min(minDiff, root->val - prev);
        prev = root->val;

        if (root->right != nullptr)
            minDiffInBST(root->right);

        return minDiff;
    }
};