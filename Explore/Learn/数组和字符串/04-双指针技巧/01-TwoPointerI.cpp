#include <iostream>
using namespace std;

void reverse(int*, int);

int main() {
  int a[5] = {0, 1, 2, 3, 4};
  int size = sizeof(a) / sizeof(*a);
  reverse(a, size);
  for (int i = 0; i < size; i += 1) {
  	cout << a[i] << endl;
  }
}


void reverse(int *v, int N) {
  int i = 0;
  int j = N - 1;
  while(i < j) {
    swap(v[i], v[j]);
	i ++;
	j --;
  }
}
