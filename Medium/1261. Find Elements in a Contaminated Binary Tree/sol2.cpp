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
        st.insert(0);
        Recover(root);
    }

    bool find(int target) {
        return !(st.find(target) == st.end());
    }

    void Recover(TreeNode* node) {
        int x = node->val;
        if (node->left) {
            int v = 2 * x + 1;
            node->left->val = 2 * x + 1;
            st.insert(v);
            Recover(node->left);
        }
        if (node->right) {
            int v = 2 * x + 2;
            node->right->val = v;
            st.insert(v);
            Recover(node->right);
        }
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */