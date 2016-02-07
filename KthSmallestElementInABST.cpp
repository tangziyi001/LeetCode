// Inorder traversal by stack
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
    stack<TreeNode*> ss;
    int kthSmallest(TreeNode* root, int k) {
        int num = 0;
        if(root == NULL){
            return NULL;
        }
        TreeNode* cur = root;
        ss.push(cur);
        while(cur->left != NULL){
            cur = cur->left;
            ss.push(cur);
        }
        
        while(!ss.empty()){
            TreeNode* now = ss.top(); ss.pop();
            num++;
            if(num == k)
                return now->val;
            if(now->right != NULL){
                TreeNode* tmp = now->right;
                ss.push(tmp);
                while(tmp->left != NULL){
                    tmp = tmp->left;
                    ss.push(tmp);
                }
            }
        }
        
    }
};