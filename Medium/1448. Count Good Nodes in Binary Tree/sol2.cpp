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
    int goodNodes(TreeNode* root) {
        return traverse(root, root -> val);
    }

    int traverse(TreeNode* root, int max) {
        if(!root) {
            return 0;
        }
        int num = 0;
        if(root -> val >= max) {
            max = root -> val;
            num = 1;
        }
        return num + traverse(root -> left, max) + traverse(root -> right, max);
    }
};