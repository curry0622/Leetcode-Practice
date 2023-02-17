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
    ListNode* sortList(ListNode* head) {
        ListNode* curr = head;
        vector<int> list;

        while (curr) {
            list.push_back(curr->val);
            curr = curr->next;
        }

        sort(list.begin(), list.end());
        ListNode* sorted;
        if (list.size() > 0) {
            sorted = new ListNode(list[0]);
            curr = sorted;
            for (int i = 1; i < list.size(); i++) {
                curr->next = new ListNode(list[i]);
                curr = curr->next;
            }
        }

        return sorted;
    }
};