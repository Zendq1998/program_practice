#include <iostream>
#include <vector>

using namespace std;

class MyCircularQueue {
private:
  vector<int> data;
  int head;
  int tail;
  bool emptyFlag = true;

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        // data.reserve(k);
        data.insert(data.begin(), k, 0);
        head = 0;
        tail = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (!isFull()) {
          data[tail] = value;
          tail = (tail + 1) % data.size();
          emptyFlag = false;
          return true;
        }
        return false;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (!isEmpty()) {
          data[head] = 0;
          head = (head + 1) % data.size();
          if (head == tail) {
            emptyFlag = true;
          }
          return true;
        }
        return false;
    }
    
    /** Get the front item from the queue. */
    int Front() {
      if (!isEmpty()) {
        return data[head];
      }
      return -1;
    }
    
    /** Get the last item from the queue. */
    int Rear() {
      if (!isEmpty()) {
        return data[tail-1 >= 0 ? tail-1 : data.size() - 1];
      }
      return -1;
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
      return emptyFlag;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if (emptyFlag) {
          return false;
        }
        return head == tail;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */