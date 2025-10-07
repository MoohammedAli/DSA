#include <iostream>
#include <vector>
using namespace std;

struct Node {
  int val;
  Node* left;
  Node* right;

  Node(int val) : val(val), left(nullptr), right(nullptr) {}


};

Node* addNode(Node* root, int x){
    if(!root) return new Node(x);
    if(root->val < x) root->right = addNode(root->right, x);
    else if(root->val > x) root->left = addNode(root->left, x);
    return root;
}

int getMin(Node* root){
  if(root->left) root->val = getMin(root->left);
  return root->val;
}

int getMax(Node* root){
  if(root->right) root->val = getMax(root->right);
  return root->val;
}



void inOrder(Node* root){
  if(!root) return;
  inOrder(root->left);
  cout << root->val << " ";
  inOrder(root->right);
}

int countNodes(Node* root){
  if(!root) return 0;
  return 1 + countNodes(root->left) + countNodes(root->right);
}

int BinarySearch(vector<int>& v, int low,int high, int target){
  if(v.size() == 0) return -1;
  else if(v.size() == 1)return low;
  else {
    int mid = (low + high) / 2;
    if(v[mid] == target) return mid;
    else if(v[mid] < target) return BinarySearch(v, mid, high, target);
    else return BinarySearch(v, low, mid, target);
  }
  return -1;
}

int main(){
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);
  cout << BinarySearch(v,0,v.size(),5) << endl;
}
