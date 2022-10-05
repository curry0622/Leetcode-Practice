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
    TreeNode* addOneRow(TreeNode* root, const int& val, int depth, bool isLeft = true) {
        if(depth == 1) {
            TreeNode* left = isLeft ? root : NULL;
            TreeNode* right = !isLeft ? root : NULL;
            return new TreeNode(val, left, right);
        }
        if(root) {
            root -> left = addOneRow(root -> left, val, depth - 1);
            root -> right = addOneRow(root -> right, val, depth - 1, false);
        }
        return root;
    }
};