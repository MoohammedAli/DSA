// A Heap is a complete or almost compelete binary tree that can be constructed manually and represented in cpp as priority queue they are fast and have insertion of O(logn) deletion of O(logn) and retrieval of o(1)


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Heap {
private:
  vector<int> h; // Heap Array

public:
  Heap(){  // Constructor: To make it 1 indexed, -1 is a dummy value
    h.push_back(-1);
  }
  int size(){  // Get size function
    return (int)h.size()-1;
  }
  bool empty(){  // Check if empty function
    return size()==0;
  }
  int top(){  // get the top of the heap function
    if(empty()){
      throw runtime_error("Heap is empty");
      return h[1];
    }
  }
  void push(int x){  // Add An element to the heap
    h.push_back(x);
    int i = size();
    while(i>1&&h[i]>h[i/2]){
      swap(h[i],h[i/2]);
      i/=2;
    }
  }
  void pop(){  // Remove an element from heap
    if(empty()) throw runtime_error("Heap is empty");
    int n = size();
    swap(h[1],h[n]);
    h.pop_back();
    n--;

    int i=1;
    while(true){
      int m=i;
      if(2*i<=n&&h[2*i]>h[m]) m=2*i;
      if(2*i+1<=n&&h[2*i+1]>h[m]) m=2*i+1;
      if(m==i)break;
      swap(h[i],h[m]);
      i=m;
    }
  }
  void build(vector<int>& v){  // Transform an array into a heap
    h.clear();
    h.push_back(-1);
    for(int i=0;i<v.size();i++)h.push_back(v[i]);
    int n = size();
    for(int i=n/2;i>=1;i--)heapify(i);
  }
  void heapify(int i){  // The mechanism to transform an array into a heap
    int n = size();
    while(true){
      int m=i;
      if(2*i<=n&&h[2*i]>h[m])m=2*i;
      if(2*i+1<=n&&h[2*i+1]>h[m])m=2*i+1;
      if(i==m)break;
      swap(h[i],h[m]);
      i=m;
    }
  }
  int extractMax(){  // Return the root(max) then deletes it
    int mx = top();
    pop();
    return mx;
  }
  vector<int> heapSort(){ // Heap sort
    vector<int> result;
    Heap tmp = *this;
    while(!tmp.empty()){
      result.push_back(tmp.extractMax());
    }
    return result;
  }
};

int main() {

}
