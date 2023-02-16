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
        vector<int> values;
        ListNode* curr = head;

        while (curr) {
            values.push_back(curr->val);
            curr = curr->next;
        }

        vector<int> rev = values;
        reverse(rev.begin(), rev.end());

        return values == rev;
    }
};