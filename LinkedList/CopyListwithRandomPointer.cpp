/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> mm;
        RandomListNode* chead;
        if(head == NULL) return NULL;
        chead = new RandomListNode(head->label);
        RandomListNode* cur = head;
        RandomListNode* ccur = chead;
        mm[cur] = ccur;
        while(cur->next != NULL){
            ccur->next = new RandomListNode(cur->next->label);
            mm[cur->next] = ccur->next;
            cur = cur->next;
            ccur = ccur->next;
        }
        ccur = chead;
        cur = head;
        while(ccur != NULL){
            ccur->random = mm[cur->random];
            ccur = ccur->next;
            cur = cur->next;
        }
        return chead;
    }
};