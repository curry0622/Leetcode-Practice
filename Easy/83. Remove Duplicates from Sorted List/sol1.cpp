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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* last = NULL;
        ListNode* curr = head;
        while (curr->next) {
            last = curr;
            curr = curr->next;

            if (last->val == curr->val) {
                last->next = curr->next;
                curr = last;
            }
        }

        return head;
    }
};