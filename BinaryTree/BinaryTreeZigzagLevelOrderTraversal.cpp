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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> re;
        if(root == NULL) return re;
        queue<TreeNode*> qq;
        qq.push(root);
        qq.push(NULL);
        int rev = 0;
        while(!qq.empty()){
            TreeNode* now = qq.front(); qq.pop();
            vector<int> tmp;
            while(now != NULL){
                tmp.push_back(now->val);
                if(now->left != NULL) qq.push(now->left);
                if(now->right != NULL) qq.push(now->right);
                now = qq.front(); qq.pop();
            }
            if(!rev) re.push_back(tmp);
            else{
                reverse(tmp.begin(), tmp.end());
                re.push_back(tmp);
            }
            rev ^= 1;
            if(!qq.empty()) qq.push(NULL);
        }
        return re;
    }
};