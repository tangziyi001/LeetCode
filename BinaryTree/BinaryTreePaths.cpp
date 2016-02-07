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
    vector<int> tmp;
    vector<string> all;
    void dfs(TreeNode *now){
        tmp.push_back(now->val);
        if(now->left == NULL && now->right == NULL){
            string re = "";
            int sz = tmp.size();
            for(int i = 0; i < sz; i++){
                if(i != 0)
                    re += "->";
                re += to_string(tmp[i]);
            }
            all.push_back(re);
            tmp.pop_back();
            return ;
        }
        if(now->left)
            dfs(now->left);
        if(now->right)
            dfs(now->right);
        tmp.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL)
            return all;
        dfs(root);
        return all;
    }
};