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
        ListNode *t1 = l1, *t2 = l2, *ans = NULL;
        int sum, carry = 0;
        stack<int> s1, s2;
        while(t1 != NULL) {
            s1.push(t1 -> val);
            t1 = t1 -> next;
        }
        while(t2 != NULL) {
            s2.push(t2 -> val);
            t2 = t2 -> next;
        }
        while(!s1.empty() || !s2.empty()) {
            sum = carry;
            if(!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if(!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }
            if(sum >= 10) {
                sum -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            ListNode *newNode = new ListNode(sum);
            if(!ans) {
                ans = newNode;
            } else {
                newNode -> next = ans;
                ans = newNode;
            }
        }
        if(carry == 1) {
            ListNode *newNode = new ListNode(1);
            if(!ans) {
                ans = newNode;
            } else {
                newNode -> next = ans;
                ans = newNode;
            }
        }
        return ans;
    }
};