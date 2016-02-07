/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string re;
        queue<TreeNode*> qq;
        if(root == NULL) return "";
        qq.push(root);
        while(!qq.empty()){
            re+=" ";
            TreeNode* now = qq.front();qq.pop();
            if(now == NULL){
                re+="null";
            }
            else{
                re+=to_string(now->val);
                qq.push(now->left);
                qq.push(now->right);
            }
        }
        //cout << re << endl;
        return re;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return NULL;
        stringstream sm(data);
        int tmp = 0;
        sm >> tmp;
        TreeNode* head = new TreeNode(tmp);
        TreeNode* cur = head;
        queue<TreeNode*> qq;
        qq.push(cur);
        string l,r;
        while(sm >> l >> r){
            TreeNode* now = qq.front();qq.pop();
            if(l != "null") {
                now->left = new TreeNode(stoi(l));
                qq.push(now->left);
            }
            if(r != "null"){
                now->right = new TreeNode(stoi(r));
                qq.push(now->right);
            }
        }
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));