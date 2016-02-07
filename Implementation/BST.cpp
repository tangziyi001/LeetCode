#import <iostream>
using namespace std;
struct Node{
	int val;
	Node* left;
	Node* right;
	Node(int v) : val(v),left(NULL),right(NULL){}
};

struct BST{
	Node* root;
	int sz;
	BST() : sz(0),root(NULL){}
	void insert(int val){
		root = insert(val,root);
	}
	Node* insert(int val, Node* now){
		if(now == NULL){
			now = new Node(val);
			sz++;
		}
		else if (val <= now->val){
			now->left = insert(val,now->left);
		}
		else{
			now->right = insert(val,now->right);
		}
		return now;
	}
	void remove(int val){
		if(root != NULL){
			remove(val,root);
		}
	}
	Node* remove(int val, Node* now){
		if(now == NULL){
			return NULL;
		}
		else if(now->val < val){
			now->left = remove(val, now->left);
		}
		else if(now->val > val){
			now->right = remove(val, now->right);
		}
		else{
			now = removeNode(now);
		}
		return now;
	}
	Node* removeNode(Node* now){
		if(now->left == NULL){
			sz--;
			Node* tmp = now->right;
			delete(now);
			return tmp;
		}
		if(now->right == NULL){
			sz--;
			Node* tmp = now->left;
			delete(now);
			return tmp;
		} 
		else{
			int tmp = getPre(now->left);
			now->val = tmp;
			remove(tmp, now->left);
			return now;
		}

	}
	int getPre(Node* now){
		if(now->right != NULL) now = now->right;
		return now->val;
	}
	int size(){
		return sz;
	}
};

int main(){
	BST* mybst = new BST();
	for(int i = 0; i < 100; i++)
		mybst->insert(i);
	mybst->remove(10);
	cout << mybst->size() << endl;
	return 0;
}
