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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot -> left = root;
            root = newRoot;
        } else {
            queue<TreeNode*> que;
            que.push(root);
            int currDepth = 1;
            while(!que.empty()) {
                int num = que.size();
                if(currDepth == depth - 1) {
                    for(int i = 0; i < num; i++) {
                        TreeNode* curr = que.front();
                        TreeNode* left = curr -> left, *right = curr -> right;
                        TreeNode* newLeft = new TreeNode(val), *newRight = new TreeNode(val);
                        newLeft -> left = left;
                        newRight -> right = right;
                        curr -> left = newLeft;
                        curr -> right = newRight;
                        que.pop();
                    }
                    break;
                } else {
                    for(int i = 0; i < num; i++) {
                        TreeNode* curr = que.front();
                        if(curr -> left)
                            que.push(curr -> left);
                        if(curr -> right)
                            que.push(curr -> right);
                        que.pop();
                    }
                }
                currDepth++;
            }
        }
        return root;
    }
};