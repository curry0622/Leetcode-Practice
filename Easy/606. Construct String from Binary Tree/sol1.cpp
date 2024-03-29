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
    string tree2str(TreeNode* root) {
        string ans = "";
        traverse(root, ans);
        return ans;
    }

    void traverse(TreeNode* root, string& ans) {
        ans += to_string(root -> val);
        if(!root -> left && !root -> right)
            return;
        if(!root -> left)
            ans += "()";
        if(root -> left) {
            ans += '(';
            traverse(root -> left, ans);
            ans += ')';
        }
        if(root -> right) {
            ans += '(';
            traverse(root -> right, ans);
            ans += ')';
        }
    }
};