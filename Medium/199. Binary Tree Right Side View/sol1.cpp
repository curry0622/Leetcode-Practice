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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        vector<TreeNode*> level;
        if (root)
            level.push_back(root);

        while (level.size() > 0) {
            vector<TreeNode*> nextLevel;
            for (auto node : level) {
                if (node->left)
                    nextLevel.push_back(node->left);
                if (node->right)
                    nextLevel.push_back(node->right);
            }
            res.push_back(level.back()->val);
            level = nextLevel;
        }

        return res;
    }
};