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
    int pairSum(ListNode* head) {
        ListNode* curr = head;
        int ans = 0;
        vector<int> vec;
        while(curr) {
            vec.push_back(curr -> val);
            curr = curr -> next;
        }
        int n = vec.size();
        for(int i = 0; i < n / 2; i++) {
            if(vec[i] + vec[n - 1 - i] > ans)
                ans = vec[i] + vec[n - 1 - i];
        }
        return ans;
    }
};