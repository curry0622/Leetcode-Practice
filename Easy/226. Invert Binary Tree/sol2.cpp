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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;

        if(!root)
            return nullptr;
        q.push(root);

        while(!q.empty()) {
            TreeNode* curr = q.front();
            TreeNode* left = curr -> left;
            TreeNode* right = curr -> right;
            q.pop();

            if(left)
                q.push(left);
            if(right)
                q.push(right);

            curr -> right = left;
            curr -> left = right;
        }

        return root;
    }
};