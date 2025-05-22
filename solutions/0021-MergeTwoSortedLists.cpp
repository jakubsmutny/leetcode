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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* merged = nullptr;
        ListNode* x = nullptr;
        while(list1 && list2) {
            ListNode* &list = list2 -> val < list1 -> val ? list2 : list1;
            if(!x) merged = x = list;
            else x = x -> next = list;
            list = list -> next;
        }
        ListNode* &list = !list1 ? list2 : list1;
        if(!merged) return list;
        x -> next = list;
        return merged;
    }
};
