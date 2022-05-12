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
    int getMax(int a, int b) {
        return a > b ? a : b;
    }

    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        return 1 + getMax(maxDepth(root -> left), maxDepth(root -> right));
    }
};