// BFS with HashTable. Group nodes according to columns they belong to.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef pair<TreeNode*,int> pi;
class Solution {
public:
    map<int, vector<int> > all;
    vector<vector<int>> re;
    queue<pi> qq;
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(root == NULL) return re;
        qq.push(make_pair(root,0));
        while(!qq.empty()){
            pi now = qq.front();qq.pop();
            TreeNode* cur = now.first;
            all[now.second].push_back(cur->val);
            if(now.first->left != NULL) qq.push(make_pair(cur->left,now.second-1));
            if(now.first->right != NULL) qq.push(make_pair(cur->right,now.second+1));
        }
        //sort(all.begin(), all.end());
        for(auto it = all.begin(); it != all.end(); it++){
            re.push_back((*it).second);
        }
        return re;
    }
};