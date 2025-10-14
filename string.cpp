#include <iostream>
#include <string.h>
using namespace std;

//! String

int32_t main(){
  string s(10, 'm'); // Constructor for 10 letters of character m
  string t = "yeah";
  s.resize(5);
  s.append("Ali");
  s.push_back('m');
  s.pop_back();
  s.insert(2, "NO");  // Insert The string NO in the 2nd position
  s.insert(s.end(), t.begin(), t.end()); // Insert the string t in the end of string s in normal order
  s.erase(5, 6);  // Erase charcters from index 5 to 6
  s.replace(2, 3, "YE");  // starting index, length, new word
  s.find("m"); // find first occurence
  s.rfind('m'); // Find last occurence
  s.find_first_of('YE');
  s.substr(2,2); // Extract substring starting from index 2 length of 2
  transform(s.begin(), s.end(), s.begin(), ::toupper);  // Transform the string into uppercase string
  
  cout << s << endl;
  cout << s.capacity() << endl;
  cout << s.length() << "   " << s.size() << endl;
}
