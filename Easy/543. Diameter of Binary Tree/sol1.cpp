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
    int maxDiameter;

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxDiameter;
    }

    int height(TreeNode* root) {
        if (!root)
            return 0;
        int l = height(root->left);
        int r = height(root->right);
        maxDiameter = max(maxDiameter, l+r);
        return max(l, r) + 1;
    }
};

// Idea: the diameter of a tree is the height of left subtree + the height of right subtree