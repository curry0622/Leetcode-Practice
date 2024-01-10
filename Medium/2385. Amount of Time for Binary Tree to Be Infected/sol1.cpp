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
    unordered_map<int, vector<int>> graph;
    unordered_map<int, bool> walked;
    int amountOfTime(TreeNode* root, int start) {
        traverse(root);
        queue<int> que;
        que.push(start);
        int res = 0;
        while (!que.empty()) {
            res++;
            int cnt = que.size();
            for (int i = 0; i < cnt; i++) {
                int node = que.front();
                walked[node] = true;
                for (int nei : graph[node]) {
                    if (!walked[nei]) {
                        que.push(nei);
                    }
                }
                que.pop();
            }
        }
        return res - 1;
    }

    void traverse(TreeNode* root) {
        walked[root->val] = false;
        if (root->left) {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            traverse(root->left);
        }
        if (root->right) {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            traverse(root->right);
        }
    }
};