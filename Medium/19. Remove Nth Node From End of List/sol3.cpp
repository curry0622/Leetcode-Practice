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
        ListNode* fast = head;
        for(int i = 0; i < n; i++)
            fast = fast -> next;

        ListNode* slow = head, *prev;
        while(fast) {
            prev = slow;
            fast = fast -> next;
            slow = slow -> next;
        }

        if(prev)
            prev -> next = slow -> next;
        else
            head = head -> next;

        return head;
    }
};