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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> stk1, stk2;
        stk1.push(root1); stk2.push(root2);

        while(!stk1.empty() && !stk2.empty()) {
            if (dfs(stk1) != dfs(stk2))
                return false;
        }

        return stk1.empty() && stk2.empty();
    }

    int dfs(stack<TreeNode*>& stk) {
        while (true) {
            TreeNode* root = stk.top();
            stk.pop();
            if (root->right)
                stk.push(root->right);
            if (root->left)
                stk.push(root->left);
            if (!root->left && !root->right)
                return root->val;
        }
    }
};