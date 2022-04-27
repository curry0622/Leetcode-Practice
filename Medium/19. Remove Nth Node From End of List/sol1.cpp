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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = getLen(head);
        int pos = len - n;
        if(pos == 0) {
            head = head -> next;
            return head;
        }
        ListNode *curr = head;
        while(pos > 1) {
            pos--;
            curr = curr -> next;
        }
        if(curr -> next)
            curr -> next = curr -> next -> next;
        return head;
    }

    int getLen(ListNode* head) {
        int len = 0;
        ListNode *curr = head;
        while(curr) {
            len++;
            curr = curr -> next;
        }
        return len;
    }
};