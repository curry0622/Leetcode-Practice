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
    ListNode* swapNodes(ListNode* head, int k) {
        int len = getLen(head);
        int frontPos = k, backPos = len - k + 1;
        int frontVal = getNthNodeVal(head, frontPos);
        int backVal = getNthNodeVal(head, backPos);
        setNthNodeVal(head, frontPos, backVal);
        setNthNodeVal(head, backPos, frontVal);
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

    int getNthNodeVal(ListNode* head, int n) {
        ListNode* curr = head;
        while(n > 1) {
            curr = curr -> next;
            n--;
        }
        return curr -> val;
    }

    void setNthNodeVal(ListNode* head, int n, int val) {
        ListNode* curr = head;
        while(n > 1) {
            curr = curr -> next;
            n--;
        }
        curr -> val = val;
    }
};