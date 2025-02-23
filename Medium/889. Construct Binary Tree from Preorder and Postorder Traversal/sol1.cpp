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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        TreeNode* root = new TreeNode(pre[0]);
        if (pre.size() > 1) {
            int left = pre[1];
            int right = post[post.size()-2];
            vector<int> newPre, newPost;
            if (left != right) {
                // left
                auto it = find(pre.begin(), pre.end(), right);
                newPre = vector<int>(pre.begin() + 1, it);
                it = find(post.begin(), post.end(), left);
                newPost = vector<int>(post.begin(), it + 1);
                root->left = constructFromPrePost(newPre, newPost);

                // right
                it = find(pre.begin(), pre.end(), right);
                newPre = vector<int>(it, pre.end());
                it = find(post.begin(), post.end(), left);
                newPost = vector<int>(it + 1, post.end() - 1);
                root->right = constructFromPrePost(newPre, newPost);
            } else {
                newPre = vector<int>(pre.begin() + 1, pre.end());
                newPost = vector<int>(post.begin(), post.end() - 1);
                root->left = constructFromPrePost(newPre, newPost);
            }
        }
        return root;
    }
};