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
    TreeNode* recoverFromPreorder(string trav) {
        stack<TreeNode*> stk;
        trav += '-';
        string num(1, trav[0]);
        int depth = 0;
        for (int i = 1; i < trav.size(); i++) {
            if (trav[i] == '-') {
                if (trav[i - 1] != '-') {
                    TreeNode* node = new TreeNode(stoi(num));
                    if (stk.empty()) {
                        stk.push(node);
                    } else if (stk.size() - 1 < depth) {
                        stk.top()->left = node;
                        stk.push(node);
                    } else if (stk.size() - 1 == depth) {
                        stk.pop();
                        stk.top()->right = node;
                        stk.push(node);
                    } else {
                        int diff = stk.size() - depth;
                        while (diff-- > 0) {
                            stk.pop();
                        }
                        stk.top()->right = node;
                        stk.push(node);
                    }
                    depth = 1;
                    num = "";
                } else {
                    depth++;
                }
            } else {
                num += trav[i];
            }
        }


        TreeNode* root;
        while (!stk.empty()) {
            root = stk.top();
            stk.pop();
        }
        return root;
    }
};