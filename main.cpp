#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <deque>
#include <algorithm>
#include <sstream>
#include <math.h>
#include <array>
#define ar array
#define ll long long
using namespace std;

struct ListNode {
  int value;
  ListNode* next;

  ListNode(int value) : value(value), next(nullptr) {}
};

struct TreeNode {
  int value;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int value) : value(value), left(nullptr), right(nullptr) {}
};

class SLL {
private:
  ListNode* head;
public:
  SLL() : head(nullptr){}

  void addNodeAtFront(int value){
    ListNode* newNode = new ListNode(value);
    newNode->next = head;
    head = newNode;
  }

  void addNodeAtBack(int value){
    ListNode* newNode = new ListNode(value);
    if(!head) {head = newNode; return;}
    ListNode* temp = head;
    while(temp->next){
      temp = temp->next;
    }
    temp->next = newNode;
  }

  void deleteAtEnd(){
    if(!head){
      cout << "List is already empty" << endl;
      return;
    }
    if(!head->next){
      delete head;
      head = nullptr;
      return;
    }
    ListNode* temp = head;
    while(temp->next->next){
      temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
  }

  void deleteAtBegin(){
    if(!head){
      cout << "List is already empty" << endl;
      return;
    }
    head = head->next;
  }

  void reverseList(){
    ListNode* curr = head;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    while(curr){
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    head = prev;
  }
  void printList(){
    ListNode* temp = head;
    while(temp){
      cout << temp->value << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

class BT {
private:
  TreeNode* root;
public:
  BT() : root(nullptr) {}

  void insertInTree(int value){
    root = new TreeNode(value);

  }
};

int numberOfRookCaptures(vector<vector<char>>& board){
  int r = -1, c = -1;

  // Step1: Look for the rook
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      if(board[i][j] == 'R'){
        r = i;
        c = j;
      }
    }
  }

  int captures = 0;
  int dr[4] = {1, -1, 0, 0};
  int dc[4] = {0, 0, 1, -1};

  // Step2: Move in each direction
  for(int k = 0; k < 4; k++){
    int nr = r + dr[k], nc = c + dc[k];
    while(nr >= 0 && nr < 8 && nc >= 0 && nc < 8){
      if(board[nr][nc] == 'B') break;
      if(board[nr][nc] == 'p'){
        captures++;
        break;
      }
      nr += dr[k];
      nc += dc[k];
    }
  }
  return captures;
}

string longestPalindrome(string s){
  int n = s.size();
  if(n <= 1) return s;

  int start = 0, maxLen = 0;
  auto e = [&](int left, int right){
    while(left >= 0 && right < n && s[left] == s[right]){
      if(right - left + 1 > maxLen){
        start = left;
        maxLen = right - left + 1;
      }
      left--;
      right++;
    }
  };

  for(int i = 0; i < n; i++){
    e(i, i);
    e(i, i+1);
  }

  return s.substr(start, maxLen);
}

string simplifyPath(string path){
  vector<string> stack;
  string dir;
  stringstream ss(path);

  while(getline(ss, dir, '/')){
    if(dir == "" || dir == ".") continue;
    if(dir == ".."){
      if(!stack.empty()) stack.pop_back();
    }else{
      stack.push_back(dir);
    }
  }
  string ans = "/";
  for(int i = 0; i < stack.size(); i++){
    ans += stack[i];
    if(i < stack.size() - 1) ans += "/";
  }
  return ans;
}



int32_t main(){
  // vector<vector<char>> board = {
  //   {'.','.','.','.','.','.','.','.'},
  //   {'.','.','.','p','.','.','.','.'},
  //   {'.','.','.','R','.','.','.','p'},
  //   {'.','.','.','.','.','.','.','.'},
  //   {'.','.','.','.','.','.','.','.'},
  //   {'.','.','.','p','.','.','.','.'},
  //   {'.','.','.','.','.','.','.','.'},
  //   {'.','.','.','.','.','.','.','.'}
  // };
  // cout << numberOfRookCaptures(board) << endl;

  string str = "Moha/aasd/ed/s/as/as";
  string word;
  vector<string> strs;
  stringstream ss(str);
  while(getline(ss, word, '/')){
    strs.push_back(word);
  }
  for(string s : strs) cout << s << endl;
}
