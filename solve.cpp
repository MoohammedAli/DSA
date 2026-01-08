#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <array>
#define ar array
#define ll long long
#define ln "\n"
using namespace std;

int n, m;

bool e(int i, int j, vector<vector<int>>& grid){
  return (i<0&&j<0&&i>=n&&j>=m&&grid[i][j]==0);
}

void dfs(int i, int j, vector<vector<int>>& grid){
  if(e(i+1, j, grid)) dfs(i+1, j, grid);
  if(e(i-1, j, grid)) dfs(i-1, j, grid);
  if(e(i, j+1, grid)) dfs(i, j+1, grid);
  if(e(i, j-1, grid)) dfs(i, j-1, grid);
}

int numberOfConectedComponents(){
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m, 0));
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> grid[i][j];
    }
  }
  int ans = 0;
  vector<vector<bool>> vis(n, vector<bool>(m, false));

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(grid[i][j]==1&&!vis[i][j]){
        ans++;
        dfs(i, j, grid);
      }
    }
  }
  return ans;
}

int32_t main(){
  cout << numberOfConectedComponents() << endl;
}
