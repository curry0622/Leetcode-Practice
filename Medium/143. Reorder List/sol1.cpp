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
    void reorderList(ListNode* head) {
        stack<int> stk;
        ListNode *curr = head;
        int len = 0;
        while(curr) {
            len++;
            stk.push(curr -> val);
            curr = curr -> next;
        }
        curr = head;
        int i = 1;
        bool turn = false;
        while(i < len) {
            ListNode *newNode = new ListNode(stk.top());
            ListNode *next = curr -> next;
            curr -> next = newNode;
            i++;
            stk.pop();
            turn = true;
            if(i < len) {
                newNode -> next = next;
                i++;
                curr = next;
                turn = false;
            }
        }
        if(!turn)
            curr -> next = NULL;
    }
};