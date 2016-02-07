// Count the size; Connect the tail with the head; Find the new tail, mark the new head (next node) and set the "next" of the tail to NULL
// Corner Cases: when there is only one element; k = 0;
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
    ListNode* hh;
    int countSZ(ListNode* now){
        if(now->next == NULL){
            return 1;
        }
        return 1 + countSZ(now->next);
    }
    void connect(ListNode* now){
        if(now->next == NULL){
            now->next = hh;
        }
        else connect(now->next);
    }
    void rec(int pos, ListNode* now){
        if(pos != 1) rec(pos-1, now->next);
        else {
            re = now->next;
            now->next = NULL;
        }
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        hh = head;
        int sz = countSZ(head);
        cout << sz << endl;
        if(sz == 1 || k == 0) return head;
        if(k%sz == 0) return head;
        connect(head);
        rec(sz-k%sz,head);
        return re;
    }
};