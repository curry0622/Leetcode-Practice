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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<TreeNode*> levelNodes;

        if(root)
            levelNodes.push_back(root);
        else
            return ans;

        bool left = true;
        while(levelNodes.size() > 0) {
            int n = levelNodes.size();
            vector<int> vals(n);
            for(int i = 0; i < n; i++) {
                TreeNode* curr = levelNodes[i];
                if(left)
                    vals[i] = curr -> val;
                else
                    vals[n - 1 - i] = curr -> val;
                if(curr -> left)
                    levelNodes.push_back(curr -> left);
                if(curr -> right)
                    levelNodes.push_back(curr -> right);
            }
            levelNodes.erase(levelNodes.begin(), levelNodes.begin() + n);
            ans.push_back(vals);
            left = !left;
        }

        return ans;
    }
};