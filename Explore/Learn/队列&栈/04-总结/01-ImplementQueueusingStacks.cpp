/*
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
*/

#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> data;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        stack<int> data;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        data.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        stack<int> temp;
        while(!data.empty()) {
            temp.push(data.top());
            data.pop();
        }
        int front = temp.top();
        temp.pop();
        while(!temp.empty()) {
            data.push(temp.top());
            temp.pop();
        }
        return front;
    }
    
    /** Get the front element. */
    int peek() {
        stack<int> temp;
        while(!data.empty()) {
            temp.push(data.top());
            data.pop();
        }
        int front = temp.top();
        while(!temp.empty()) {
            data.push(temp.top());
            temp.pop();
        }
        return front;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return data.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */