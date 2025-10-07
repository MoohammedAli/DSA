#include <iostream>
using namespace std;

template <typename T>
T getMax(T a, T b){
  return a > b ? a : b;
}

template <typename T>

class Box {
private:
  T value;
public:
  Box(T v) : value(v) {}
  T getValue(){
    return value;
  }
};

int main(){
  Box<int> b(1);
  cout << b.getValue() << endl;
}
