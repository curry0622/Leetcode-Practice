/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* curr = node, *next = NULL, *last = NULL;
        while(curr -> next) {
            curr -> val = curr -> next -> val;
            last = curr;
            curr = curr -> next;
        }
        last -> next = NULL;
    }
};