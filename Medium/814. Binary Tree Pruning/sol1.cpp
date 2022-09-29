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
    TreeNode* pruneTree(TreeNode* root) {
        if(!hasOne(root))
            root = NULL;
        return root;
    }

    bool hasOne(TreeNode* root) {
        if(!root)
            return false;
        bool left = hasOne(root -> left);
        bool right = hasOne(root -> right);
        if(root -> left && !left)
            root -> left = NULL;
        if(root -> right && !right)
            root -> right = NULL;
        return root -> val || left || right;
    }
};