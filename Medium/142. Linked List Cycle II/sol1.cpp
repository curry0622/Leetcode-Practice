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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> traversed;
        while (head) {
            if (traversed.find(head) == traversed.end()) {
                traversed.insert(head);
                head = head->next;
            } else
                return head;
        }
        return nullptr;
    }
};