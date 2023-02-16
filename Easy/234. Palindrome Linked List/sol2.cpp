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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = head;

        while (fast) {
            if (fast->next)
                fast = fast->next;
            else
                break;
            prev = fast;
            fast = fast->next;
            slow = slow->next;
        }
        if (!fast)
            fast = prev;

        reverseList(slow);

        slow = head;
        while (slow && fast) {
            if (slow->val != fast->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }

        return true;
    }

    void reverseList(ListNode* head) {
        if (!head)
            return;

        ListNode* curr = head->next;
        ListNode* prev = head;
        prev->next = NULL;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }
};