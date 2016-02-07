/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // Use a pointer backpack
class Solution {
public:
    ListNode* tmp = NULL;
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* nxt = NULL;
        while(cur != NULL){
            nxt = cur->next;
            cur->next = tmp;
            tmp = cur;
            cur = nxt;
        }
        return tmp;
    }
};