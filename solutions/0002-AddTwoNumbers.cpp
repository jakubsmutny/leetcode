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
        ListNode* result = nullptr;
        ListNode* x = nullptr;
        int carry = 0;
        while(l1 || l2 || carry) {
            if(!x) result = x = new ListNode();
            else x = x -> next = new ListNode();
            x -> val = (l1 ? l1 -> val : 0) + (l2 ? l2 -> val : 0) + carry;
            carry = x -> val / 10;
            x -> val = x -> val % 10;
            if(l1) l1 = l1 -> next;
            if(l2) l2 = l2 -> next;
        }
        return result;
    }
};
