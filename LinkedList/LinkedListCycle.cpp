/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        ListNode* cur1 = head;
        ListNode* cur2 = head;
        while(cur2->next != NULL && cur2->next->next != NULL){
            cur2 = cur2->next->next;
            cur1 = cur1->next;
            if(cur1 == cur2) return true;
        }
        return false;
    }
};