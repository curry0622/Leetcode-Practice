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
    TreeNode* insertIntoBST(TreeNode *root, int val) {
        if(!root) {
            TreeNode *newNode = new TreeNode(val);
            root = newNode;
        } else
            binarySearch(root, val);
        return root;
    }

    void binarySearch(TreeNode *root, int val) {
        int curr = root -> val;
        if(val < curr) {
            if(root -> left) {
                binarySearch(root -> left, val);
            } else {
                TreeNode *newNode = new TreeNode(val);
                root -> left = newNode;
            }
        } else {
            if(root -> right) {
                binarySearch(root -> right, val);
            } else {
                TreeNode *newNode = new TreeNode(val);
                root -> right = newNode;
            }
        }
    }
};