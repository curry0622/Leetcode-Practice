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
class BSTIterator {
public:
    stack<TreeNode*> stk;

    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    int next() {
        TreeNode* tmp = stk.top();
        stk.pop();
        pushLeft(tmp->right);
        return tmp->val;
    }

    bool hasNext() {
        return !stk.empty();
    }

    void pushLeft(TreeNode* root) {
        while (root) {
            stk.push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

// stk[7, 3
// pop 3
// pop 7
// stk[15, 9
// pop 9
// pop 15
// stk[20
// pop 20
// stk[
