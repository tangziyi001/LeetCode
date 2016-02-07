// Merge two adjacent lists and push it back to the queue until there is only one head in the queue.
// This solution is slow.
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
    queue<ListNode*> qq;
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* head = new ListNode(-1);
        ListNode* cur = head;
        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2-> val){
                //cout << cur->val << "in 1" << endl;
                cur->next = new ListNode(l1->val);
                cur = cur->next;
                l1 = l1->next;
            }
            else if(l1->val > l2->val){
                //cout << cur->val << "in 2" << endl;
                cur->next = new ListNode(l2->val);
                cur = cur->next;
                l2 = l2->next;
            }
        }
        while(l1 != NULL){
            //cout << cur->val << "in 1" << endl;
            cur->next = new ListNode(l1->val);
            l1 = l1->next;
            cur = cur->next;
        }
        while(l2 != NULL){
            //cout << cur->val << "in 2" << endl;
            cur->next = new ListNode(l2->val);
            l2 = l2->next;
            cur = cur->next;
        }
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int sz = lists.size();
        if(sz == 0) return NULL;
        for(int i = 0; i < sz; i++){
            if(lists[i] != NULL)
                qq.push(lists[i]);
        }
        if(qq.size() == 0) return NULL;
        while(qq.size() > 1){
            ListNode* q1 = qq.front();qq.pop(); cout << q1->val << endl;
            ListNode* q2 = qq.front();qq.pop(); cout << q2->val << endl;
            ListNode* cur = merge(q1,q2);
            qq.push(cur);
        }
        return qq.front();
    }
};