#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <set>
#include <array>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
const int mxN = 1e5;
#define ar array


/*
    [                             [
                                    0 1 3 6 10
                                    5 11 18 26
                                  ]
      1 2 3 4
      5 6 7 8
      9 10 11 12
      13 14 15 16
    ]
*/


int twoDPrefix(vector<vector<int>>& grid){
  int n = grid.size(), m = grid[0].size();
  vector<vector<int>> pref(n+1, vector<int>(m+1));
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      pref[i][j] = grid[i-1][j-1] + pref[i][j-1] + pref[i-1][j] - pref[i-1][j-1];
    }
  }
}

void solve(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(m+1, vector<int>(n+1));
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      cin >> grid[i][j];
    }
  }
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      grid[i][j] += grid[i][j-1];
   }
  }
   for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      grid[i][j] += grid[i-1][j];
    }
  }
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      cout << grid[i][j] << ' ';
    }
    cout << endl;
  }
}

int32_t main(){
  solve();
}
