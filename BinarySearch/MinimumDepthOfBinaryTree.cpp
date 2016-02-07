// Binary tree depth problem: each node's min depth is 1 + min(left child depth, right child depth).
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
    int rec(TreeNode* now){
        if(now->left == NULL && now->right == NULL){
            return 1;
        }
        int minp = (int)1E9;
        if(now->left != NULL) minp = min(minp, 1 + rec(now->left));
        if(now->right != NULL) minp = min(minp, 1 + rec(now->right));
        return minp;
    }
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return rec(root);
    }
};