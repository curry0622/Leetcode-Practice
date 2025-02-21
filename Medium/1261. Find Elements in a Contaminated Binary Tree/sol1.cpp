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
public:
    FindElements(TreeNode* r) {
        root = r;
        root->val = 0;
        Recover(root);
    }

    bool find(int target) {
        return find(target, root);
    }

    void Recover(TreeNode* node) {
        int x = node->val;
        if (node->left) {
            node->left->val = 2 * x + 1;
            Recover(node->left);
        }
        if (node->right) {
            node->right->val = 2 * x + 2;
            Recover(node->right);
        }
    }

    bool find(int target, TreeNode* node) {
        if (!node) return false;
        if (node->val == target) return true;
        return find(target, node->left) || find(target, node->right);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */