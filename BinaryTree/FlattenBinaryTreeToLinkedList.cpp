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
vector<TreeNode*> all;
public:
    void rec(TreeNode* cur){
        all.push_back(cur);
        if(cur->left) rec(cur->left);
        if(cur->right) rec(cur->right);
    }
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        TreeNode* cur = root;
        cur = root;
        rec(cur);
        int sz = all.size();
        for(int i = 1; i < sz; i++){
            cur->right = all[i];
            cur->left = 0;
            cur = cur->right;
        }
        
    }
};