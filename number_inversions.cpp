#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <sstream>
#include <complex.h>
#include <queue>
using namespace std;

int bruteForce(int a[],int n){  // O(N^2)
  int numberOfInversions = 0;
  for(int i=0;i<5;i++){
    for(int j=i+1;j<5;j++){
      numberOfInversions+=(a[i]>a[j]);
    }
  }
  return numberOfInversions;
}

void insert(vector<int>& v, int x){
  v.push_back(x);
  int i = v.size() - 1;
  while(i>1&&v[i]>v[i/2]){
    swap(v[i],v[i/2]);
    i/=2;
  }
}

int getMax(vector<int>& v){
  return v[1];
}

void pop(vector<int>& v){
  int n = v.size()-1;
  swap(v[1],v[n]);
  v.pop_back();
  n--;

  int i = 1;
  while(true){
    int m = i;
    if(2*i<=n&&v[2*i]>v[m])m=2*i;
    if(2*i+1<=n&&v[2*i+1]>v[m])m=2*i+1;
    if(m==i)break;
    swap(v[i],v[m]);
    i=m;
  }
}

void heapSort(vector<int>& v){
  vector<int> tmp=v;
  while(tmp.size()>1){
    cout<<getMax(tmp)<<" ";
    pop(tmp);
  }
}

void shuffle(vector<int>& v){
  for(int i=0;i<v.size();i++){
    swap(v[i],v[rand()%(int)v.size()-1]);
  }
}

void bogoSort(vector<int>& v){
  while(!is_sorted(v.begin(),v.end())){
    shuffle(v);
  }
}



int main() {
  string x1,x2,y1,y2;
  int i1,i2;
  double xr1,xr2,yr1,yr2;
  string num1 = "1+-1i", num2 = "0+0i";
  for(int i=0;i<num1.size();i++){
    if(num1[i]=='+'){i1=i+1;break;}
    x1+=num1[i];
  }
  for(int i=i1;i<num1.size();i++){
    if(num1[i]=='i')break;
    y1+=num1[i];
  }
   for(int i=0;i<num2.size();i++){
    if(num2[i]=='+'){i2=i+1;break;}
    x2+=num2[i];
  }
  for(int i=i2;i<num2.size();i++){aa
    if(num2[i]=='i')break;
    y2+=num2[i];
  }
  cout << x1 << y1 << x2 << y2 << endl;
  xr1 = stoi(x1);
  xr2 = stoi(x2);
  yr1 = stoi(y1);
  yr2 = stoi(y2);
  complex<double> numa1(xr1,yr1), numa2(xr2,yr2);
  complex<double> result = numa1 * numa2;
  ostringstream oss;
  oss << result.real();
  if(result.imag() >= 0){
    oss << "+";
  }
  oss << result.imag() << "i";
  string ans = oss.str();
  cout<<ans<<endl;
}
