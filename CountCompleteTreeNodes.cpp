/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Dig into left and right of the tree to see if it is complete. If it is, then
// add 2^n-1 to the total sum; Otherwise, check left and right subtree and then add 1.
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int l = 1, r = 1;
        TreeNode* ll = root; TreeNode* rr = root;
        while(ll->left != NULL){
            ll = ll->left;
            l++;
        }
        while(rr->right != NULL){
            rr = rr->right;
            r++;
        }
        if(l == r){
            return pow(2,l)-1;
        } else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};