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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;

        ListNode* oddCurr = head;
        ListNode* evenCurr = head->next;
        ListNode* evenHead = evenCurr;
        ListNode* curr = evenCurr->next;

        bool oddPhase = true;
        while (curr) {
            if (oddPhase) {
                oddCurr->next = curr;
                oddCurr = oddCurr->next;
            } else {
                evenCurr->next = curr;
                evenCurr = evenCurr->next;
            }
            oddPhase = !oddPhase;
            curr = curr->next;
        }
        evenCurr->next = nullptr;
        oddCurr->next = evenHead;

        return head;
    }
};