#include <iostream>
using namespace std;

int main() {
  string s1 = "Hello World!";
  cout << "s1 is \"Hello World!\"" << endl;
  string s2 = s1;
  cout << "s2 is initialed by s1" << endl;
  string s3(s1);
  cout << "s3 is initialed by s1" << endl;
  // compare by '=='
  cout << "Compared by '==':" << endl;
  cout << "s1 and \"Hello World!\": " << (s1 == "Hello World!") << endl;
  cout << "s1 and s2: " << (s1 ==s2) << endl;
  cout << "s1 and s3: " << (s1 == s3) << endl;
  // compare by 'compare'
  cout << "compared by 'compare':" << endl;
  cout << "s1 and \"Hello world!\":" << !s1.compare("Hello World!") << endl;
  cout << "s1 and s2: " << !s1.compare(s2) << endl;
  cout << "s1 and s3: " << !s1.compare(s3) << endl;
  s1[5] = ',';
  cout << s1 << endl;
  s1 += "!";
  cout << s1 << endl;
  // find
  cout << "The position of first 'o' is: " << s1.find('o') << endl;
  cout << "The position of last 'o' is: " << s1.rfind('o') << endl;
 // get substr
 cout << s1.substr(6, 5) << endl; 
 cout << s1.size() << endl;
}
