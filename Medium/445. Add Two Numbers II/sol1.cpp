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
        return reverse(
            addTwoNumbersV1(reverse(l1), reverse(l2))
        );
    }

    ListNode* addTwoNumbersV1(ListNode* l1, ListNode* l2) {
        int carry  = 0;
        ListNode *ans = new ListNode(-1);
        ListNode *curr = ans;
        while(l1 && l2) {
            int sum = l1 -> val + l2 -> val + carry;
            if(sum >= 10) {
                carry = 1;
                sum -= 10;
            } else {
                carry = 0;
            }
            ListNode* newNode = new ListNode(sum);
            curr -> next = newNode;
            curr = curr -> next;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while(l1) {
            int sum = l1 -> val + carry;
            if(sum >= 10) {
                carry = 1;
                sum -= 10;
            } else {
                carry = 0;
            }
            ListNode* newNode = new ListNode(sum);
            curr -> next = newNode;
            curr = curr -> next;
            l1 = l1 -> next;
        }
        while(l2) {
            int sum = l2 -> val + carry;
            if(sum >= 10) {
                carry = 1;
                sum -= 10;
            } else {
                carry = 0;
            }
            ListNode* newNode = new ListNode(sum);
            curr -> next = newNode;
            curr = curr -> next;
            l2 = l2 -> next;
        }
        if(carry == 1) {
            ListNode *newNode = new ListNode(1);
            curr -> next = newNode;
            curr = curr -> next;
        }
        return ans -> next;
    }

    ListNode* reverse(ListNode *head) {
        ListNode *curr = head;
        ListNode *prev = NULL, *next = NULL;
        while (curr) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};