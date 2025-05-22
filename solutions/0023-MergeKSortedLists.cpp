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

struct CompareNodes {
    bool operator()(ListNode* a, ListNode* b) {
        if(!a) return true;
        if(!b) return false;
        return a -> val > b -> val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareNodes> nodeQueue;
        for(ListNode* list : lists)
            nodeQueue.push(list);
        ListNode* merged = nullptr;
        ListNode* x = nullptr;
        while(!nodeQueue.empty()) {
            ListNode* node = nodeQueue.top();
            nodeQueue.pop();
            if(!node) break;
            nodeQueue.push(node -> next);
            if(!x) merged = x = node;
            else x = x -> next = node;
        }
        return merged;
    }
};
