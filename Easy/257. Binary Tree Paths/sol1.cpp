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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        traverse(root, res, path);
        return res;
    }

    string makePathStr(const vector<int>& path) {
        string res = "";
        for (int i = 0; i < path.size() - 1; i++) {
            res += to_string(path[i]) + "->";
        }
        res += to_string(path.back());
        return res;
    }

    void traverse(TreeNode* root, vector<string>& res, vector<int>& path) {
        path.push_back(root->val);
        if (!root->left && !root->right) {
            res.push_back(makePathStr(path));
        } else if (!root->right) {
            traverse(root->left, res, path);
        } else if (!root->left) {
            traverse(root->right, res, path);
        } else {
            traverse(root->left, res, path);
            traverse(root->right, res, path);
        }
        path.pop_back();
    }
};