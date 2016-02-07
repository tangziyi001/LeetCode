/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #import <stack>
class BSTIterator {
public:
    TreeNode *cur = NULL;
    stack<TreeNode*> ss;
    BSTIterator(TreeNode *root) {
       cur = root;
       while(cur != NULL){
           ss.push(cur);
           cur = cur->left;
       }
    }
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(!ss.empty())
            return true;
        return false;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* now = ss.top();
        ss.pop();
        if(now->right != NULL){
            TreeNode* tmp = now->right;
            while(tmp != NULL){
                ss.push(tmp);
                tmp = tmp->left;
            }
        }
        
        return now->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */