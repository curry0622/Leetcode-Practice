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
        ListNode* slow = head;

        // First move fast ptr n times
        for (int i = 0; i < n; i++)
            fast = fast->next;

        // Move fast & slow ptr simultaneously until fast ptr reach the end
        // and also record the previous ptr of slow ptr
        ListNode* prev = NULL;
        while (fast) {
            prev = slow;
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the next node of the prev ptr
        if (!prev)
            head = head->next;
        else
            prev->next = slow->next;

        return head;
    }
};