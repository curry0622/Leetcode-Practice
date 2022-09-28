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
        int num = 0;
        traverse(root, INT_MIN, num);
        return num;
    }

    void traverse(TreeNode* root, int max, int& num) {
        if(!root) {
            return;
        }
        if(root -> val >= max) {
            max = root -> val;
            num++;
        }
        traverse(root -> left, max, num);
        traverse(root -> right, max, num);
    }
};