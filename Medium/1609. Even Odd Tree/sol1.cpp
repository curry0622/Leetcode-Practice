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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int level = 0;
        while (!q.empty()) {
            int n = q.size();
            int last;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                int curr = node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                if (level % 2 == curr % 2)
                    return false;
                if (i != 0) {
                    if (level % 2 == 1) {
                        // Odd
                        if (last <= curr)
                            return false;
                    } else {
                        // Even
                        if (last >= curr)
                            return false;
                    }
                }
                last = curr;
            }
            level++;
        }

        return true;
    }
};