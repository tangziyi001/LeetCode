// Recursively reverse elements from each group until the number of nodes remained is smaller than k
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
    int mark = 0;
    ListNode* rec(ListNode* cur,int idx,int k){
        if(idx > mark) return cur;
        ListNode* tmp = NULL;
        ListNode* start = cur;
        ListNode* nxt = cur;
        while(cur){
            nxt = cur->next;
            cur->next = tmp;
            tmp = cur;
            cur = nxt;
            if((idx+1)%k == 0){
                start->next = rec(cur,idx+1,k);
                break;
            }
            idx++;
        }
        return tmp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return NULL;
        if(k == 1) return head;
        ListNode* cur = head;
        int num = 0;
        while(cur){
            num++;
            cur = cur->next;
        }
        mark = num - num%k - 1;
        return head = rec(head,0,k);
    }
};