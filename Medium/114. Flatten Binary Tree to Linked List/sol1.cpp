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
    void flatten(TreeNode* root) {
        if(!root)
            return;
        TreeNode *ans = new TreeNode();
        DLR(root, ans);
        *root = *(ans -> right);
    }

    TreeNode* DLR(TreeNode* root, TreeNode* ans) {
        TreeNode *newNode = new TreeNode(root -> val);
        ans -> right = newNode;
        ans = ans -> right;
        if(root -> left)
            ans = DLR(root -> left, ans);
        if(root -> right)
            ans = DLR(root -> right, ans);
        return ans;
    }
};