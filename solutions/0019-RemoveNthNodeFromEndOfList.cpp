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
        int m = 0;
        ListNode* x = head;
        do ++m; while(x = x -> next);
        m -= n;
        x = head;
        ListNode* p = nullptr;
        for(int i = 0; i < m; ++i) {
            p = x;
            x = x -> next;
        }
        if(p) p -> next = x -> next;
        else head = head -> next;
        delete x;
        return head;
    }
};
