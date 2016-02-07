// If the cur node equals to p or q, then set that node as the target node, return true.
// If the cur node has left branch returned true and right branch returned true, this node 
// is the target node.
// If the cur node has either brach retured true, it also returns true.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* re;
    bool rec(TreeNode* cur, TreeNode* p, TreeNode* q){
        if(cur == p){
            re = p; 
            return true;
        }
        if(cur == q){
            re = q;
            return true;
        }
        bool flag1 = false;
        bool flag2 = false;
        if(cur->left){
            flag1 = rec(cur->left,p,q);
        }
        if(cur->right){
            flag2 = rec(cur->right,p,q);
        }
        if(flag1 && flag2){
            re = cur;
            return true;
        }
        if(flag1 || flag2){
            return true;
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        rec(root,p,q);
        return re;
    }
};