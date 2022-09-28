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
        vector<ListNode*> record;
        ListNode* curr = head;
        int len = 0;

        while(curr) {
            len++;
            record.push_back(curr);
            curr = curr -> next;
        }

        int idx = len - n;
        if(idx == 0)
            head = head -> next;
        else
            record[idx - 1] -> next = record[idx] -> next;

        return head;
    }
};