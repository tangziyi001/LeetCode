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
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        TreeNode* cur = root;
        ss.push(cur);
        cur = cur->left;
        while(cur != NULL){
            ss.push(cur);
            cur = cur->left;
        }
        double nowVal = ss.top()->val-0.001;
        while(!ss.empty()){
            TreeNode* now = ss.top();ss.pop();
            int val = now->val;
            if(val <= nowVal) return false;
            else nowVal = val;
            now = now->right;
            while(now != NULL){
                ss.push(now);
                now = now->left;
            }
        }
        return true;
    }
};