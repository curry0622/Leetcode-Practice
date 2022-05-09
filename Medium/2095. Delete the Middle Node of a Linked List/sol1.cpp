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
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int n = 0;
        ListNode *curr = head;
        while(curr) {
            n++;
            curr = curr -> next;
        }
        curr = head;
        for(int i = 0; i < n / 2 - 1; i++) {
            curr = curr -> next;
        }
        if(curr -> next)
            curr -> next = curr -> next -> next;
        else
            head = NULL;
        return head;
    }
};