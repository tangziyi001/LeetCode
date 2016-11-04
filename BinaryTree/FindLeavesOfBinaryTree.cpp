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
    map<int, vector<int>> mm;
    int rec(TreeNode* cur){
        if(cur == NULL) return 0;
        int idx = 1+max(rec(cur->left), rec(cur->right));
        if(mm.count(idx) == 0){
            mm[idx] = vector<int>(0,0);
        }
        mm[idx].push_back(cur->val);
        return idx;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        rec(root);
        vector<vector<int>> re;
        for(auto it = mm.begin(); it != mm.end(); it++){
            re.push_back(it->second);
        }
        return re;
    }
};