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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> ss;
        vector<int> re;
        TreeNode* cur = root;
        while(cur != NULL){
            ss.push(cur);
            cur = cur->left;
        }
        while(!ss.empty()){
            TreeNode* now = ss.top();ss.pop();
            re.push_back(now->val);
            now = now->right;
            while(now != NULL){
                ss.push(now);
                now = now->left;
            }
        }
        return re;
    }
};