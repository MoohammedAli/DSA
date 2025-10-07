#include <iostream>
#include <vector>
using namespace std;
#define ll long long


int cnt[150];

void countingSort(){
 int n;
  cin >> n;
  for(int i=1;i<=n;i++){
    int x;
    cin >> x;
    cnt[x]++;
  }
  for(int i=1;i<=100;i++){
    for(int j=1;j<=cnt[i];j++){
      cout << i << " ";
    }
  }
  cout << endl;
}

int main(){
  string s, ans = "";
  cin >> s;
  int freq[26] = {0};
  for(char c : s)freq[c-'a']++;
  for(int i=0;i<26;i++){
    char a = i + 'a';
    for(int j=0;j<freq[i];j++){
      ans+=a;
    }
  }
  cout << ans << endl;
}
