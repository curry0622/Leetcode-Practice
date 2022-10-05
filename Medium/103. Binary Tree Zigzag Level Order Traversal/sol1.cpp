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

        while(levelNodes.size() > 0) {
            vector<int> vals;
            int n = levelNodes.size();
            for(int i = 0; i < n; i++) {
                TreeNode* curr = levelNodes[i];
                vals.push_back(curr -> val);
                if(curr -> left)
                    levelNodes.push_back(curr -> left);
                if(curr -> right)
                    levelNodes.push_back(curr -> right);
            }
            levelNodes.erase(levelNodes.begin(), levelNodes.begin() + n);
            ans.push_back(vals);
        }

        bool left = true;
        for(int i = 0; i < ans.size(); i++, left = !left) {
            if(!left)
                reverse(ans[i].begin(), ans[i].end());
        }

        return ans;
    }
};