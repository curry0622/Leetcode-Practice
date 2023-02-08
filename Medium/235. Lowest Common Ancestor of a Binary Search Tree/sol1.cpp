/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<TreeNode*> path_p, path_q;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = root;
        vector<TreeNode*> path;
        dfs(root, p, q, path);
        for (int i = 0; i < min(path_p.size(), path_q.size()); i++) {
            if (path_p[i] == path_q[i])
                ans = path_p[i];
            else
                break;
        }
        return ans;
    }

    void dfs(TreeNode* root, TreeNode* p, TreeNode* q, vector<TreeNode*>& path) {
        if(!root)
            return;
        path.push_back(root);
        if (root == p)
            path_p = path;
        if (root == q)
            path_q = path;
        dfs(root->left, p, q, path);
        dfs(root->right, p, q, path);
        path.pop_back();
    }
};