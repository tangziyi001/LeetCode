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
    int rec(TreeNode* node){
        if(node->left == NULL && node->right == NULL)
            return 1;
        else if(node->left == NULL)
            return 1+rec(node->right);
        else if(node->right == NULL)
            return 1+rec(node->left);
        else
            return 1+max(rec(node->right), rec(node->left));
            
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return rec(root);
    }
};