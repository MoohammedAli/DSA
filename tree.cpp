#include <iostream>
#include <queue>
using namespace std;

struct Node {
  int val;
  Node* left;
  Node* right;
  Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int x){
  if(!root){
    return new Node(x);
  }
  if(root->val < x) root->left = insert(root->left, x);
  else if(root->val > x) root->right = insert(root->right, x);
  return root;
}

int findMin(Node* root){
  while(root->left) root = root->left;
  return root->val;
}

int findMax(Node* root){
  while(root->right) root = root->right;
  return root->val;
}

int height(Node* root){
  if(!root) return 0;
  return 1 + max(height(root->left), height(root->right));
}


void inOrder(Node* root){
  if(!root) return;
  inOrder(root->left);
  cout << root->val << " ";
  inOrder(root->right);
}

void preOrder(Node* root){
  if(!root) return;
  cout << root-> val << " ";
  preOrder(root->left);
  preOrder(root->right);
}

void postOrder(Node* root){
  if(!root) return;
  postOrder(root->left);
  postOrder(root->right);
  cout << root->val << " ";
}

void levelOrder(Node* root){
  if(!root) return;
  queue<Node*> q;
  q.push(root);
  while(!q.empty()){
    Node* cur = q.front(); q.pop();
    cout << cur->val << " ";
    if(cur->left) q.push(cur->left);
    if(cur->right) q.push(cur->right);
  }
}



int main(){
  Node* root = nullptr;
  root = insert(root, 1);
  root = insert(root, 2);
  root = insert(root, 3);

  inOrder(root);

}
