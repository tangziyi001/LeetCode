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
    bool check(TreeNode* cur1, TreeNode* cur2){
        if(cur1 == NULL && cur2 == NULL) return true;
        if(cur1 == NULL || cur2 == NULL) return false;
        return check(cur1->left, cur2->right) && check(cur1->right, cur2->left) && cur1->val == cur2->val;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return check(root->left, root->right);
    }
};