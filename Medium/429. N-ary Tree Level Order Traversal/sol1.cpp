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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<Node*> q;
        q.push(root);
        ans.push_back(vector<int>(1, root -> val));
        while(!q.empty()) {
            vector<int> tmp;
            vector<Node*> lvlNodes;
            while(!q.empty()) {
                lvlNodes.push_back(q.front());
                q.pop();
            }
            for(auto node: lvlNodes) {
                if(!(node -> children).empty()) {
                    for(auto child: node -> children) {
                        tmp.push_back(child -> val);
                        q.push(child);
                    }
                }
            }
            if(!tmp.empty())
                ans.push_back(tmp);
        }
        return ans;
    }
};
