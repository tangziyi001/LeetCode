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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* cur = head;
        re = new ListNode(cur->val);
        ListNode* now = re;
        if(cur->next == NULL) return re;
        while(cur->next != NULL && cur->next->next != NULL){
            now->next = new ListNode(cur->next->next->val);
            now = now->next;
            cur = cur->next->next;
        }
        cur = head->next;
        now->next = new ListNode(cur->val);
        now = now->next;
        while(cur->next != NULL && cur->next->next != NULL){
            now->next = new ListNode(cur->next->next->val);
            now = now->next;
            cur = cur->next->next;
        }
        return re;
    }
};