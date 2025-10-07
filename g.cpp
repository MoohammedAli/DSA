#include <iostream>
#include <set>
#include <unordered_map>
#include <bitset>
#include <array>
#include <string.h>
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
  if(root->val < x) root->left = addNode(root->left, x);
  else if(root->val > x) root->right = addNode(root->right, x);
  return root;
}

bool search(Node* root, int x){
  if(!root) return false;
  if(root->val == x) return true;
  else if(root->val < x) return search(root->left, x);
  else if(root->val > x) return search(root->right,x );
  return false;
}

void inOrder(Node* root){
  if(!root) return;
  inOrder(root->left);
  cout << root->val << " ";
  inOrder(root->right);
}

int subarrayDividedByK(vector<int>& v, int k){
  unordered_map<int, int> remainderCount;
  remainderCount[0] = 1;

  int prfx = 0, ans = 0;
  for(int num : v){
    prfx += num;
    int rem = ((prfx % k) + k) % k;
    if(remainderCount.count(rem)){
      ans++;
    }
    remainderCount[rem]++;
  }
  return ans;

}

int32_t main(){
  bitset<(1u << 21) + 1> count;
  array<uint8_t, 265> table;
  string s = "mohammed";
  set<int> st;
  st.
}
