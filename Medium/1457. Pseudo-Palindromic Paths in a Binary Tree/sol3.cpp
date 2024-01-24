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
    int validCnt;
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> cnt(9, 0);
        validCnt = 0;
        dfs(root, cnt);
        return validCnt;
    }

    void dfs(TreeNode* root, vector<int>& cnt) {
        cnt[root->val-1]++;
        if (!root->left && !root->right) {
            if (isPseudoPalindromic(cnt))
                validCnt++;
            cnt[root->val-1]--;
            return;
        }
        if (root->left)
            dfs(root->left, cnt);
        if (root->right)
            dfs(root->right, cnt);
        cnt[root->val-1]--;
    }

    bool isPseudoPalindromic(const vector<int>& cnt) {
        int len = 0;
        int oddCnt = 0;

        for (int n : cnt) {
            len += n;
            oddCnt += n % 2;
        }

        return len % 2 == oddCnt;
    }
};