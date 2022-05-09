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
        ListNode* curr = head;
        vector<int> vec;
        while(curr) {
            vec.push_back(curr -> val);
            curr = curr -> next;
        }
        for(int i = 0; i < vec.size() / 2; i++) {
            if(vec[i] != vec[vec.size() - 1 - i])
                return false;
        }
        return true;
    }
};