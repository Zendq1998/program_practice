/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/

#include <iostream>
#include <vector>

using namespace std;


class MinStack {
private:
    int min;
    vector<int> data; 
public:
    /** initialize your data structure here. */
    MinStack() {
        min = INT_MAX;
    }
    
    void push(int x) {
        data.push_back(x);
        if (x < min) {
            min = x;
        }
    }
    
    void pop() {
        if (data.size()) {
            if (top() == min) {
                min = INT_MAX;
                for (int i = 0; i < data.size() - 1; i += 1) {
                    if (data[i] < min) {
                        min = data[i];
                    }
                }
            }
            data.pop_back();
        }
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */