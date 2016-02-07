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
    vector<int> re;
    void rec(TreeNode* now){
        if(now->left) rec(now->left);
        if(now->right) rec(now->right);
        re.push_back(now->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return re;
        rec(root);
        return re;
    }
};