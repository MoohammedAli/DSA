#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

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
