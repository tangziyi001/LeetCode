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
    int maxp = 0;
    int counter(TreeNode* root){
       int l,r;
        l=r=1;
        if(root->left){
            int t = counter(root->left);
            if((root->left)->val == root->val+1)
                l+=t;
        }
        if(root->right){
            int t = counter(root->right);
            if((root->right)->val == root->val+1)
                r+=t;
        }
        maxp = max(maxp,max(l,r));
        return max(l,r);
    }
    int longestConsecutive(TreeNode* root) {
        int l,r;
        l=r=1;
        if(root == NULL)
            return 0;
        if(root->left){
            int t = counter(root->left);
            if((root->left)->val == root->val+1)
                l+=t;
        }
        if(root->right){
            int t = counter(root->right);
            if((root->right)->val == root->val+1)
                r+=t;
        }
        maxp = max(maxp,max(l,r));
        return maxp;
    }
};