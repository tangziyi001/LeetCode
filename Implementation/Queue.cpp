#import <iostream>
using namespace std;

struct Node{
	int val;
	Node* next;
	Node(int v) : val(v),next(0){}
};

struct Queue{
	Node* head;
	Node* tail;
	int sz;
	Queue() : sz(0), head(0){}
	void push(int val){
		if(head == 0){
			head = new Node(val);
			tail = head;
		}
		else{
			tail->next = new Node(val);
			tail = tail->next;
		}
		sz++;
	}
	void pop(){
		if(head == 0){
			cout << "NO ELEMENT" << endl;
			return ;
		}
		Node* cur = head;
		head = head->next;
		delete(cur);
		sz--;
	}
	int peek(){
		if(head == 0){
			cout << "NO ELEMENT" << endl;
			return 0;
		}
		return head->val;
	}
	int size(){return sz;}
};

int main(){
	Queue* myqueue = new Queue();
	myqueue->push(12);
	myqueue->push(20);
	myqueue->push(30);
	cout << myqueue->size() << endl;
	myqueue->pop();
	cout << myqueue->peek() << endl;
	return 0;
}