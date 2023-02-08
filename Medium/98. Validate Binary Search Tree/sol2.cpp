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
    bool isValidBST(TreeNode* root, long long min = LLONG_MIN, long long max = LLONG_MAX) {
        if (!root)
            return true;

        bool self, left, right;
        self = min < root->val && root->val < max;

        long long left_min, left_max;
        left_min = min;
        left_max = max < root->val ? max : root->val;
        left = isValidBST(root->left, left_min, left_max);

        long long right_min, right_max;
        right_min = min > root->val ? min : root->val;
        right_max = max;
        right = isValidBST(root->right, right_min, right_max);

        return self && left && right;
    }
};