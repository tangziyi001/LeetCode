#import <iostream>
#import <vector>
using namespace std;


// Stack via Linked List
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int v) : val(v){}
};

struct Stack{
	ListNode* top;
	int sz;
	Stack() : sz(0),top(0){}
	void push(int val){
		if(top == 0) top = new ListNode(val);
		else{
			ListNode* cur = new ListNode(val);
			cur->next = top;
			top = cur;
		}
		sz++;
	}
	int peek(){
		if(top == 0){
			cout << "NO ELEMENT" << endl;
			return 0;
		}
		return top->val;
	}
	void pop(){
		if(top == 0){
			cout << "NO ELEMENT" << endl;
			return ;
		}
		ListNode* cur = top;
		top = top->next;
		delete(cur);
		sz--;
	}
	int size(){return sz;}
};


int main(){
	Stack* mystack = new Stack();
	mystack->push(10);
	mystack->push(20);
	cout << mystack->peek() << endl;
	mystack->pop();
	cout << mystack->peek() << endl;
	cout << mystack->size() << endl;
	mystack->pop();
	mystack->pop();
}