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
    ListNode* re;
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        re = new ListNode(head->val);
        ListNode* cur = head;
        ListNode* now = re;
        while(cur->next){
            if(cur->next->val != cur->val){
                now->next = new ListNode(cur->next->val);
                now = now->next;
            }
            cur = cur->next;
        }
        return re;
    }
};