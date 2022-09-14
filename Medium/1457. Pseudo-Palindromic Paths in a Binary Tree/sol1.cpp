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
    int pseudoPalindromicPaths (TreeNode* root) {
        int cnt = 0;
        traverse(root, vector<int>(9, 0), cnt);
        return cnt;
    }

    void traverse(TreeNode* root, vector<int> record, int& cnt) {
        if(root) {
            record[(root -> val) - 1]++;
        }
        if(root -> left) {
            traverse(root -> left, record, cnt);
        }
        if(root -> right) {
            traverse(root -> right, record, cnt);
        }
        if(!root -> left && !root -> right) {
            int num = 0;
            for(int n: record) {
                num += n;
            }
            if(num % 2 == 0) {
                cnt++;
                for(int n: record) {
                    if(n % 2 != 0) {
                        cnt--;
                        break;
                    }
                }
            } else {
                int odd = 0;
                for(int n: record) {
                    if(n % 2 != 0) {
                        odd++;
                    }
                }
                if(odd == 1)
                    cnt++;
            }
        }
    }
};