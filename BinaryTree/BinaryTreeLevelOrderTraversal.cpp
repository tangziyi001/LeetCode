// Binary Tree with BFS
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef vector<int> vi;
typedef vector<vi> vvi;
class Solution {
public:
    vi tmp;
    vvi re;
    queue<TreeNode*> qq;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return re;
        qq.push(root);
        TreeNode* ttmp = new TreeNode(1000000000);
        qq.push(ttmp);
        while(!qq.empty()){
            TreeNode* now = qq.front();qq.pop();
            if(now->val == 1000000000){
                re.push_back(tmp);
                tmp.clear();
                if(!qq.empty()){
                    TreeNode* ttmp = new TreeNode(1000000000);
                    qq.push(ttmp); 
                }
                continue;
            }
            tmp.push_back(now->val);
            if(now->left) qq.push(now->left);
            if(now->right) qq.push(now->right);
        }
        return re;
    }
};