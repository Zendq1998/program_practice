#include <iostream>
#include <vector>

using namespace std;

class MyStack {
  private:
    vector<int> data;
  public:
    /** Insert an element into the stack */
    void push(int x) {
      data.push_back(x);
    }
    /** Check whether the stack is empty or not */
    bool isEmpty() {
      return data.empty();
    }
    /** Get the top from the stack */
    int top() {
      return data.back();
    }
    /** Delete an element from the stack. Return true of the operation is successful. */
    bool pop() {
      if(isEmpty()) {
        return false;
      }
      data.pop_back();
      return true;
    }
};

int main() {
  MyStack s;
  s.push(1);
  s.push(2);
  s.push(3);
  for (int i = 0; i < 4; i += 1) {
    if (!s.isEmpty()) {
      cout << s.top() << endl;
    }
    cout << (s.pop() ? "true" : "false") << endl;
  }
}