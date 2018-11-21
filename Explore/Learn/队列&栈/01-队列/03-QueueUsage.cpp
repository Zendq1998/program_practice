#include <iostream>
#include <queue>

using namespace std;

int main() {
  // Initialize
  queue<int> q;
  q.push(5);
  q.push(5);
  q.push(13);
  q.push(8);
  q.push(6);
  // Check if queue is empty
  if (q.empty()) {
    cout << "Queue is empty!" << endl;
    return 0;
  }
  // Pop an element
  q.pop();
  // Get the first element
  cout << "The first element is: " << q.front() << endl;
  // Get the last element
  cout << "The last element is: " << q.back() << endl;
  // Get the size of the queue.
  cout << "The size is: " << q.size() << endl;
}