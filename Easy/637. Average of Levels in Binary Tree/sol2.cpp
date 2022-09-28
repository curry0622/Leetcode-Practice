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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int num = que.size();
            long sum = 0;
            for(int i = 0; i < num; i++) {
                TreeNode* front = que.front();
                sum += front -> val;
                if(front -> left)
                    que.push(front -> left);
                if(front -> right)
                    que.push(front -> right);
                que.pop();
            }
            ans.push_back(double(sum) / double(num));
        }
        return ans;
    }
};