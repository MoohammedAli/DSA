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

class st {
private:
  vector<int> tree;
  int n;

  // Builds the segment tree
  void build(vector<int>& nums, int node, int start, int end){
    if(start == end){
      tree[node] = nums[start];
    }else{
      int mid = (start + end) / 2;
      build(nums, 2*node, start, mid);
      build(nums, 2*node+1, mid+1, end);
      tree[node] = tree[2*node] + tree[2*node+1];
    }
  }

  // Queries from specific range, returns the sum of numbers from L to R inclusive
  int query(int node, int start, int end, int L, int R){
    if(R < start || end < L){
      return 0;
    }
    if(L <= start && end <= R){
      return tree[node];
    }
    int mid = (start + end) / 2;
    int leftSum = query(2*node, start, mid, L, R);
    int rightSum = query(2*node+1, mid+1, end, L, R);
    return leftSum + rightSum;
  }

  // Updates Range fromt start to end
  void update(int node, int start, int end, int idx, int val){
    if(start == end){
      tree[node] = val;
    }else{
      int mid = (start + end) / 2;
      if(idx <= mid){
        update(2*node, start, mid, idx, val);
      }else{
        update(2*node+1, mid+1, end, idx, val);
      }
      tree[node] = tree[2*node] + tree[2*node+1];
    }
  }

public:
  st(vector<int>& nums){
    n = nums.size();
    tree.resize(4*n);
    build(nums, 1, 0, n-1);
  }

  int query(int L, int R){
    return query(1, 0, n-1, L, R);
  }

  void update(int idx, int val){
    return update(1, 0, n-1, idx, val);
  }
};

int32_t main(){
  vector<int> nums = {1,2,3,4,5,6};
  st s(nums);
  cout << s.query(1,3) << endl;
}
