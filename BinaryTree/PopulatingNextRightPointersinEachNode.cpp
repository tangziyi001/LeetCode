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
    void dfs(TreeLinkNode* now, unordered_map<int, TreeLinkNode*>& mm, int level){
        if(mm.count(level) == 0)
            mm[level] = now;
        else {
            mm[level]->next = now;
            mm[level] = now;
        }
        if(now->left != NULL) dfs(now->left, mm, level+1);
        if(now->right != NULL) dfs(now->right, mm, level+1);
    }
    void connect(TreeLinkNode *root) {
        unordered_map<int, TreeLinkNode*> mm;
        if(root == NULL) return ;
        dfs(root, mm, 0);
    }
};