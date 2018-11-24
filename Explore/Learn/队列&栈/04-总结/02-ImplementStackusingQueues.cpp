/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
*/

#include <iostream>
#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> data;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        data.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int> temp;
        int top;
        while(!data.empty()) {
            if(data.size() > 1) {
                temp.push(data.front());
            }
            else {
                top = data.front();
            }
            data.pop();
        }
        while(!temp.empty()) {
            data.push(temp.front());
            temp.pop();
        }
        return top;
    }
    
    /** Get the top element. */
    int top() {
        return data.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return data.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */