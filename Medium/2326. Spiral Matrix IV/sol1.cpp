/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
enum Dir {
    RIGHT, DOWN, LEFT, UP
};
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        Dir d = RIGHT;
        int i = 0, j = 0;
        while (head) {
            res[i][j] = head->val;
            switch (d) {
                case Dir::RIGHT:
                    j++;
                    if (j >= n || res[i][j] != -1) {
                        j--, i++;
                        d = Dir::DOWN;
                    }
                    break;
                case Dir::DOWN:
                    i++;
                    if (i >= m || res[i][j] != -1) {
                        i--, j--;
                        d = Dir::LEFT;
                    }
                    break;
                case Dir::LEFT:
                    j--;
                    if (j < 0 || res[i][j] != -1) {
                        j++, i--;
                        d = Dir::UP;
                    }
                    break;
                case Dir::UP:
                    i--;
                    if (i < 0 || res[i][j] != -1) {
                        i++, j++;
                        d = Dir::RIGHT;
                    }
                    break;
            }
            head = head->next;
        }
        return res;
    }
};