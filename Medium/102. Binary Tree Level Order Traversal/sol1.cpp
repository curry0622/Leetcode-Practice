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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        ans.push_back(vector<int>(1, root -> val));
        while(!q.empty()) {
            vector<int> tmp;
            vector<TreeNode*> lvlNodes;
            while(!q.empty()) {
                lvlNodes.push_back(q.front());
                q.pop();
            }
            for(auto node: lvlNodes) {
                if(node -> left) {
                    tmp.push_back(node -> left -> val);
                    q.push(node -> left);
                }
                if(node -> right) {
                    tmp.push_back(node -> right -> val);
                    q.push(node -> right);
                }
            }
            if(tmp.size() != 0)
                ans.push_back(tmp);
        }
        return ans;
    }
};
