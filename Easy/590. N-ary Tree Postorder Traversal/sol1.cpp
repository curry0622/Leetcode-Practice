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
    void LRD(Node* root, vector<int>& vec) {
        if(!root)
            return;
        for(auto node: root -> children)
            LRD(node, vec);
        vec.push_back(root -> val);
    }

    vector<int> postorder(Node* root) {
        vector<int> ans;
        LRD(root, ans);
        return ans;
    }
};