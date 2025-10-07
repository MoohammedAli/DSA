#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

void subsets(vector<vector<int> >& ans, vector<int>& subset, vector<int>& nums, int idx){
  ans.push_back(subset);
  for(int i=idx;i<nums.size();i++){
    subset.push_back(nums[i]);
    subsets(ans, subset, nums, i+1);
    subset.pop_back();
  }
}

string decimalToBinary(int n){
  string ans = "";
  while(n){
    if(n%2){
      ans.push_back('1');
    }else{
      ans.push_back('0');
    }
    n/=2;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int binaryToDecimal(string binary){
  int ans = 0, powerOfTwo = 1;
  int len = binary.length();
  for(int i = len - 1; ~i; i--){
    if(binary[i] == '1') ans += powerOfTwo;
    powerOfTwo *= 2;
  }
  return ans;
}

int32_t main(){
  string n;
  cin >> n;
  // cout << decimalToBinary(n) << endl;
  cout << binaryToDecimal(n) << endl;
}
