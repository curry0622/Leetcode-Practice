/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void DLR(Node* root, vector<int>& vec) {
        if(!root)
            return;
        vec.push_back(root -> val);
        for(auto node: root -> children)
            DLR(node, vec);
    }

    vector<int> preorder(Node* root) {
        vector<int> ans;
        DLR(root, ans);
        return ans;
    }
};