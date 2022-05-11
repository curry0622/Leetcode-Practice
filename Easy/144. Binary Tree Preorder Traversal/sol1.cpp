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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        DLR(root, ans);
        return ans;
    }

    void DLR(TreeNode* root, vector<int>& vec) {
        if(!root) {
            return;
        } else {
            vec.push_back(root -> val);
            DLR(root -> left, vec);
            DLR(root -> right, vec);
        }
    }
};