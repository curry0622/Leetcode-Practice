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
    vector<vector<int>> levelNodes;

    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        traverse(root, 1);
        for(vector<int> nodes: levelNodes) {
            long sum = 0;
            for(int val: nodes)
                sum += val;
            ans.push_back(double(sum) / double(nodes.size()));
        }
        return ans;
    }

    void traverse(TreeNode* root, int level) {
        if(!root) {
            return;
        }
        if(levelNodes.size() < level) {
            levelNodes.push_back(vector<int>{root -> val});
        } else {
            levelNodes[level - 1].push_back(root -> val);
        }
        traverse(root -> left, level + 1);
        traverse(root -> right, level + 1);
    }
};