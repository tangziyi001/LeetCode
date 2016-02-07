// Use a map to record the cur node in each level
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int,TreeLinkNode*> all;
    void rec(TreeLinkNode* cur, int idx){
        if(all.find(idx) == all.end()){
            all[idx] = cur;
            cur->next = NULL;
        }
        else{
            cur->next = all[idx];
            all[idx] = cur;
        }
        if(cur->right) rec(cur->right,idx+1);
        if(cur->left) rec(cur->left,idx+1);
    }
    void connect(TreeLinkNode *root) {
        if(root != NULL)
            rec(root,0);
    }
};