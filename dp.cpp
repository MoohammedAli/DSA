#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <sstream>
#include <climits>
#include <queue>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <list>
#include <cassert>
#define DEBUG false
#define ll long long
#define OJ_DEBUG
#define ln "\n"
using namespace std;
const int MOD = 1e9 + 7;
const ll INF = 4e18;

string TOLOWER(string s) {
  string ans = "";
  for (char c : s) {
    ans+=tolower(c);
  }
  return ans;
}



int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, t; cin >> n >> t;
  vector<int> a(n);
  for (int i=0; i<n; i++) cin >> a[i];
  sort(a.begin(), a.end());
}
