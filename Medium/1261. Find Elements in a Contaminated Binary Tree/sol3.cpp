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
class FindElements {
TreeNode* root;
unordered_set<int> st;

public:
    FindElements(TreeNode* r) {
        root = r;
        root->val = 0;
        Recover(root, 0);
    }

    bool find(int target) {
        return st.count(target);
    }

    void Recover(TreeNode* node, int val) {
        if (!node) return;
        st.insert(val);
        Recover(node->left, 2 * val + 1);
        Recover(node->right, 2 * val + 2);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */