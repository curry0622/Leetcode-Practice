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
TreeNode* res;
int currMax = 0;

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        postOrder(root, 0);
        return res;
    }

    int postOrder(TreeNode* root, int d) {
        if (!root) return d;
        int l = postOrder(root->left, d + 1);
        int r = postOrder(root->right, d + 1);
        if (l == r && l >= currMax) {
            currMax = l;
            res = root;
        }
        return max(l, r);
    }
};