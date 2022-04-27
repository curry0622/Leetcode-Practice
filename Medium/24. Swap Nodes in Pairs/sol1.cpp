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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head -> next)
            return head;
        ListNode *curr = head, *next = head -> next, *prev = NULL;
        bool first = true;
        while(curr && next) {
            // switch
            curr -> next = next -> next;
            next -> next = curr;
            if(first) {
                // update head
                first = false;
                head = next;
                prev = curr;
            } else {
                // update prev and connect
                prev -> next = next;
                prev = curr;
            }
            if(!curr -> next) {
                break;
            }
            // update curr & next
            curr = curr -> next;
            next = curr -> next;
        }
        return head;
    }
};