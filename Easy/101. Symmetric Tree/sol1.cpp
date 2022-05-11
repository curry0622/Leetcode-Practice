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
    bool isSymmetric(TreeNode* root) {
        if(!root -> left && !root -> right)
            return true;
        if(!root -> left || !root -> right)
            return false;
        vector<int> lVec, rVec;
        mirror(root -> right);
        traverse(root -> left, lVec);
        traverse(root -> right, rVec);
        for(int i = 0; i < lVec.size(); i++) {
            if(lVec[i] != rVec[i])
                return false;
        }
        return true;
    }

    void mirror(TreeNode* root) {
        if(!root)
            return;
        TreeNode* tmpNode = root -> left;
        root -> left = root -> right;
        root -> right = tmpNode;
        mirror(root -> left);
        mirror(root -> right);
    }

    void traverse(TreeNode* root, vector<int>& vec) {
        if(!root) {
            vec.push_back(101);
            return;
        }
        vec.push_back(root -> val);
        traverse(root -> left, vec);
        traverse(root -> right, vec);
    }
};