// Use stack to traverse the tree. Fill the vector with size k from small element to large element.
// If vector is full, check if the new element is closer to target. If so, remove the smallest element
// from the vector and add the new one. If not, then all larger element cannot be added into the vector.
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
    vector<int> all;
    stack<TreeNode*> sta;
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        if(root == NULL) return all;
        if(k == 0) return all;
        TreeNode* node = root;
        sta.push(node);
        while(node->left != NULL){
            sta.push(node->left);
            node = node->left;
        }
        while(!sta.empty()){
            TreeNode* now = sta.top(); sta.pop();
            if(all.size() < k){
                all.push_back(now->val);
            }
            else{
                int tmp = *all.begin();
                if(abs(tmp-target) > abs(now->val - target)){
                    all.erase(all.begin());
                    all.push_back(now->val);
                }
                else{
                    break;
                }
            }
            if(now->right != NULL){
                TreeNode* RR = now->right;
                sta.push(RR);
                while(RR->left != NULL){
                    sta.push(RR->left);
                    RR = RR->left;
                }
            }
        }
        return all;
    }
};