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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* curr = res;
        ListNode* last = NULL;

        while (l1 && l2) {
            curr->val += l1->val + l2->val;
            curr->next = new ListNode(curr->val / 10);
            curr->val %= 10;
            cout << curr->val << endl;

            last = curr;
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            curr->val += l1->val;
            curr->next = new ListNode(curr->val / 10);
            curr->val %= 10;
            cout << curr->val << endl;

            last = curr;
            curr = curr->next;
            l1 = l1->next;
        }
        while (l2) {
            curr->val += l2->val;
            curr->next = new ListNode(curr->val / 10);
            curr->val %= 10;
            cout << curr->val << endl;

            last = curr;
            curr = curr->next;
            l2 = l2->next;
        }

        if (curr->val == 0) {
            last->next = NULL;
        }

        return res;
    }
};