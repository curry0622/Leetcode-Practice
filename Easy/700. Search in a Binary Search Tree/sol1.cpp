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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode *ans = NULL;
        while(true) {
            if(root -> val < val) {
                if(root -> right) {
                    root = root -> right;
                } else {
                    break;
                }
            } else if(root -> val > val) {
                if(root -> left) {
                    root = root -> left;
                } else {
                    break;
                }
            } else {
                ans = root;
                break;
            }
        }
        return ans;
    }
};