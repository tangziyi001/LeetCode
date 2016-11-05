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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> re;
        stack<vector<int>> ss;
        vector<int> tmp;
        queue<TreeNode*> qq;
        if(root == NULL) return re;
        qq.push(root);
        qq.push(NULL);
        while(!qq.empty()){
            TreeNode* now = qq.front(); qq.pop();
            if(now == NULL){
                if(!qq.empty()) qq.push(NULL);
                ss.push(tmp);
                tmp.clear();
                continue;
            }
            tmp.push_back(now->val);
            if(now->left != NULL) qq.push(now->left);
            if(now->right != NULL) qq.push(now->right);
        }
        while(!ss.empty()){
            re.push_back(ss.top()); ss.pop();
        }
        return re;
    }
};