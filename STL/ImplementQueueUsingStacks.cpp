class Queue {
public:
    stack<int> ll;
    stack<int> rr;
    // Push element x to the back of queue.
    void push(int x) {
        while(!rr.empty()){
            ll.push(rr.top());rr.pop();
        }
        ll.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        while(!ll.empty()){
            rr.push(ll.top());ll.pop();
        }
        rr.pop();
    }

    // Get the front element.
    int peek(void) {
        while(!ll.empty()){
            rr.push(ll.top());ll.pop();
        }
        return rr.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return ll.empty() && rr.empty();
    }
};