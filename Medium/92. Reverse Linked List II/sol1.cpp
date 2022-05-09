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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *curr = head, *prev = NULL, *next = NULL, *start = NULL, *end = NULL, *startNext = NULL, *endPrev = NULL;
        int i = 0;
        while(curr) {
            i++;
            next = curr -> next;
            if(i == left - 1) {
                start = curr;
            }
            if(i == left) {
                endPrev = curr;
            }
            if(i == right) {
                startNext = curr;
            }
            if(i == right + 1) {
                end = curr;
            }
            if(left <= i && i <= right) {
                curr -> next = prev;
            }
            prev = curr;
            curr = next;
        }
        if(start)
            start -> next = startNext;
        else
            head = startNext;
        if(endPrev)
            endPrev -> next = end;
        return head;
    }
};