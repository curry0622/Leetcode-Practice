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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        stk.push(root);

        while(!stk.empty()) {
            TreeNode* curr = stk.top();
            if(!curr || curr -> val == INT_MIN) {
                stk.pop();
                continue;
            }
            if(curr -> left && curr -> left -> val != INT_MIN) {
                stk.push(curr -> left);
                continue;
            }
            ans.push_back(curr -> val);
            curr -> val = INT_MIN;
            if(curr -> right && curr -> right -> val != INT_MIN) {
                stk.push(curr -> right);
                continue;
            }
            stk.pop();
        }

        return ans;
    }
};