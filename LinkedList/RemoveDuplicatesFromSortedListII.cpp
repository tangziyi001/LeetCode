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
    ListNode* rec(ListNode* cur){
        if(cur == NULL) return NULL;
        ListNode* tmp = cur->next;
        while(tmp != NULL && tmp->val == cur->val){
            tmp = tmp->next;
        }
        if(tmp == cur->next){
            cur->next = rec(tmp);
            return cur;
        }
        else return rec(tmp);
    }
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        return rec(cur);
    }
};